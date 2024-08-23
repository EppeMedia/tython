#!/bin/bash

###########
## SETUP ##
###########

FLAG_TYTHON="--tython"
FLAG_CPYTHON="--cpython"
FLAG_CODON="--codon"
FLAG_ALL="--all"

# Check if the correct number of arguments is provided
if [ "$#" -le 2 ]; then
  echo "Usage: $0 <benchmarks_source_directory> <iterations> <COMPILER...>, with COMPILER := { $FLAG_TYTHON, $FLAG_CPYTHON, $FLAG_CODON, $FLAG_ALL }"
  exit 1
fi

run_tython=0
run_cpython=0
run_codon=0

for arg in "$@"
do
    if [ "$arg" == "$FLAG_TYTHON" ] || [ "$arg" == "$FLAG_ALL" ]; then
        run_tython=1
        break
    fi

    if [ "$arg" == "$FLAG_CPYTHON" ] || [ "$arg" == "$FLAG_ALL" ]; then
        run_cpython=1
        break
    fi

    if [ "$arg" == "$FLAG_CODON" ] || [ "$arg" == "$FLAG_ALL" ]; then
        run_codon=1
        break
    fi
done




# Assign arguments to variables
DIR_PATH=$1
ITERATIONS=$2

OUTPUT_PATH="results"
TYTHON_OUTPUT_FILE="$OUTPUT_PATH/tython_benchmark_results.tex"
CPYTHON_OUTPUT_FILE="$OUTPUT_PATH/cpython_benchmark_results.tex"
CODON_OUTPUT_FILE="$OUTPUT_PATH/codon_benchmark_results.tex"

# Check if the source directory exists
if [ ! -d "$DIR_PATH" ]; then
  echo "Directory $DIR_PATH does not exist."
  exit 1
fi

mkdir -p "$OUTPUT_PATH"

###############
## END SETUP ##
###############

#######################
## UTILITY FUNCTIONS ##
#######################

# Function to calculate median
calculate_median() {
  arr=($(printf '%s\n' "$@" | sort -n))
  count=${#arr[@]}
  if (( $count % 2 == 0 )); then
    echo "(${arr[$count/2-1]} + ${arr[$count/2]}) / 2" | bc -l
  else
    echo "${arr[$count/2]}"
  fi
}

# Function to calculate mean
calculate_mean() {
  sum=0
  count=$#
  for time in "$@"; do
    sum=$(echo "$sum + $time" | bc -l)
  done
  echo "$sum / $count" | bc -l
}

# Function to calculate variance
calculate_variance() {
  mean=$(calculate_mean "$@")
  sum=0
  count=$#
  for time in "$@"; do
    diff=$(echo "$time - $mean" | bc -l)
    sum=$(echo "$sum + $diff * $diff" | bc -l)
  done
  echo "$sum / $count" | bc -l
}

# Function to prepend underscores with a backslash
escape_underscores() {
  local input="$1"
  local escaped=$(echo "$input" | sed 's/_/\\_/g')
  echo "$escaped"
}

# Function to truncate a number to a specified number of decimal places
truncate_number() {
  local number="$1"
  local decimals="$2"
  printf "%.${decimals}f\n" "$number"
}

get_filename_without_extension() {
  local filepath="$1"
  # Extract the base name and remove the extension
  local filename=$(basename "$filepath")
  local name="${filename%.*}"
  echo "$name"
}

measure_time() {

  PERF_OUTPUT=$(chrt -f 99 perf stat -e user_time,instructions,system_time -x ' ' ""$@"" 2>&1 > /dev/null)

  readarray -t lines <<< "$PERF_OUTPUT"

  read -r user_time _ <<< "${lines[0]}"
  read -r instructions _ <<< "${lines[1]}"
  read -r system_time_raw _ <<< "${lines[2]}"

  system_time="${system_time_raw:-0}"

  REAL_TIME=$(($user_time + $system_time))

  # Output time in seconds
  echo $(bc -l <<< "scale=4; $REAL_TIME/1000000000")
}

######################
## START BENCHMARKS ##
######################

# create build directory
mkdir -p build

##################
## START TYTHON ##
##################

if [ $run_tython -eq 1 ]; then

  echo "+---------------------+"
  echo "| BENCHMARKING TYTHON |"
  echo "+---------------------+"

  truncate -s 0 "$TYTHON_OUTPUT_FILE"

  ####################
  ## DEFINE CONFIGS ##
  ####################

  config1="-d --no-specialize"
  config2="-d --no-specialize --no-guards"
  config3="-d"
  config4=""

  declare -a configs=("$config1" "$config2" "$config3" "$config4")

  ########################
  ## START CONFIG TABLE ##
  ########################

  # generate the configurations table
    echo "\begin{table}[hbt]" >> $TYTHON_OUTPUT_FILE
    echo "\centering" >> $TYTHON_OUTPUT_FILE
    echo "\begin{tabular}{ll}" >> $TYTHON_OUTPUT_FILE
    echo "Label & Compiler flags \\\\" >> $TYTHON_OUTPUT_FILE
    echo "\toprule" >> $TYTHON_OUTPUT_FILE

  it=0
  for CONFIG in "${configs[@]}"; do
    
    ((it++))

    echo "Configuration$it & \lstinline[]\$$CONFIG\$ \\\\" >> $TYTHON_OUTPUT_FILE
    echo "\midrule" >> $TYTHON_OUTPUT_FILE

  done


  # Finalize the LaTeX table
  echo "\end{tabular}" >> $TYTHON_OUTPUT_FILE
  echo "\caption{The benchmark build configurations.}\label{tab:build_configurations}" >> $TYTHON_OUTPUT_FILE
  echo "\end{table}" >> $TYTHON_OUTPUT_FILE

  ######################
  ## END CONFIG TABLE ##
  ######################

  it=0
  for CONFIG in "${configs[@]}"; do
    
    ((it++))

    # Initialize the LaTeX table
    echo "\noindent" >> $TYTHON_OUTPUT_FILE
    echo "\begin{table}[hbt]" >> $TYTHON_OUTPUT_FILE
    echo "\centering" >> $TYTHON_OUTPUT_FILE
    echo "\begin{tabular}{lllllllll}" >> $TYTHON_OUTPUT_FILE

    echo "    & \thead{Fastest \\ Time (s)} & \thead{Mean \\ Time (s)} & \thead{Median \\ Time (s)} & \thead{Max \\ Time (s)} & \thead{Variance (s\$^2\$)} \\\\" >> $TYTHON_OUTPUT_FILE

    echo "\toprule" >> $TYTHON_OUTPUT_FILE

    # Loop over all Tython files in the directory
    for FILE in "$DIR_PATH"/*.ty; do
      # Check if there are any Tython files
      if [ ! -e "$FILE" ]; then
        echo "No Tython files found in the directory."
        exit 1
      fi

      # extract executable name
      EXECUTABLE_NAME=$(get_filename_without_extension "$FILE")"_$it"

      BUILD_COMMAND="./tython -m $FILE -l /home/manzi/repos/tython/cmake-build-debug/lib/src/libtython_lib.a -o build/$EXECUTABLE_NAME $CONFIG &> /dev/null"

      echo "+------------------------+"
      echo "| Build configuration $it: | $BUILD_COMMAND"
      echo "+------------------------+"

      times=()

      # build the executable
      eval "$BUILD_COMMAND"
      
      # Run the benchmark for the specified number of iterations
      for (( i=1; i<=ITERATIONS; i++ )); do

        EXECUTION_TIME=$(measure_time "build/$EXECUTABLE_NAME")
        
        echo "|- $EXECUTABLE_NAME: $EXECUTION_TIME"

        times+=($EXECUTION_TIME)

      done
      
      # Log the fastest time to the LaTeX table
      escaped_name=$(escape_underscores "$EXECUTABLE_NAME")

      # Calculate statistics
      r=$(echo "${times[@]}" | tr ' ' '\n' | sort -n | head -n 1)
      fastest_time=$(truncate_number "$r" 4)
      r=$(calculate_mean "${times[@]}")
      mean_time=$(truncate_number "$r" 4)
      r=$(calculate_median "${times[@]}")
      median_time=$(truncate_number "$r" 4)
      r=$(echo "${times[@]}" | tr ' ' '\n' | sort -n | tail -n 1)
      max_time=$(truncate_number "$r" 4)
      r=$(calculate_variance "${times[@]}")
      variance_time=$(truncate_number "$r" 4)

      echo "$escaped_name & $fastest_time & $mean_time & $median_time & $max_time & $variance_time \\\\" >> $TYTHON_OUTPUT_FILE
      echo "\midrule" >> $TYTHON_OUTPUT_FILE

    done

    # Finalize the LaTeX table
    echo "\end{tabular}" >> $TYTHON_OUTPUT_FILE
    echo "\caption{The benchmark results for Configuration$it ($ITERATIONS iterations).}\label{tab:benchmark_results$it}" >> $TYTHON_OUTPUT_FILE
    echo "\end{table}" >> $TYTHON_OUTPUT_FILE

  done

  echo "+-----------------+"
  echo "| FINISHED TYTHON |"
  echo "+-----------------+"
  echo "| output written: | $TYTHON_OUTPUT_FILE"
  echo "+-----------------+"

fi

################
## END TYTHON ##
################

###################
## START CPYTHON ##
###################

if [ $run_cpython -eq 1 ]; then

  echo "+----------------------+"
  echo "| BENCHMARKING CPYTHON |"
  echo "+----------------------+"

  truncate -s 0 "$CPYTHON_OUTPUT_FILE"

  # Initialize the LaTeX table
  echo "\noindent" >> $CPYTHON_OUTPUT_FILE
  echo "\begin{table}[hbt]" >> $CPYTHON_OUTPUT_FILE
  echo "\centering" >> $CPYTHON_OUTPUT_FILE
  echo "\begin{tabular}{lllllllll}" >> $CPYTHON_OUTPUT_FILE

  echo "    & \thead{Fastest \\ Time (s)} & \thead{Mean \\ Time (s)} & \thead{Median \\ Time (s)} & \thead{Max \\ Time (s)} & \thead{Variance (s\$^2\$)} \\\\" >> $CPYTHON_OUTPUT_FILE

  echo "\toprule" >> $CPYTHON_OUTPUT_FILE

  # Loop over all Python files in the directory
  for FILE in "$DIR_PATH"/*.py; do

    # extract executable name
    EXECUTABLE_NAME=$(get_filename_without_extension "$FILE")

    times=()

    # Run the benchmark for the specified number of iterations
      for (( i=1; i<=ITERATIONS; i++ )); do

        EXECUTION_TIME=$(measure_time "python3 $FILE")
        
        echo "|- $EXECUTABLE_NAME: $EXECUTION_TIME"

        times+=($EXECUTION_TIME)

      done
      
      # Log the fastest time to the LaTeX table
      escaped_name=$(escape_underscores "$EXECUTABLE_NAME")

      # Calculate statistics
      r=$(echo "${times[@]}" | tr ' ' '\n' | sort -n | head -n 1)
      fastest_time=$(truncate_number "$r" 4)
      r=$(calculate_mean "${times[@]}")
      mean_time=$(truncate_number "$r" 4)
      r=$(calculate_median "${times[@]}")
      median_time=$(truncate_number "$r" 4)
      r=$(echo "${times[@]}" | tr ' ' '\n' | sort -n | tail -n 1)
      max_time=$(truncate_number "$r" 4)
      r=$(calculate_variance "${times[@]}")
      variance_time=$(truncate_number "$r" 4)

      echo "$escaped_name & $fastest_time & $mean_time & $median_time & $max_time & $variance_time \\\\" >> $CPYTHON_OUTPUT_FILE
      echo "\midrule" >> $CPYTHON_OUTPUT_FILE

  done

  # Finalize the LaTeX table
  echo "\end{tabular}" >> $CPYTHON_OUTPUT_FILE
  echo "\caption{The benchmark results for CPython ($ITERATIONS iterations).}\label{tab:benchmark_results_cpython}" >> $CPYTHON_OUTPUT_FILE
  echo "\end{table}" >> $CPYTHON_OUTPUT_FILE


  echo "+------------------+"
  echo "| FINISHED CPYTHON |"
  echo "+------------------+"
  echo "| output written:  | $CPYTHON_OUTPUT_FILE"
  echo "+------------------+"

fi

#################
## END CPYTHON ##
#################

#################
## START CODON ##
#################

if [ $run_codon -eq 1 ]; then

  echo "+--------------------+"
  echo "| BENCHMARKING CODON |"
  echo "+--------------------+"

  # Initialize the LaTeX table
  echo "\noindent" >> $CODON_OUTPUT_FILE
  echo "\begin{table}[hbt]" >> $CODON_OUTPUT_FILE
  echo "\centering" >> $CODON_OUTPUT_FILE
  echo "\begin{tabular}{lllllllll}" >> $CODON_OUTPUT_FILE

  echo "    & \thead{Fastest \\ Time (s)} & \thead{Mean \\ Time (s)} & \thead{Median \\ Time (s)} & \thead{Max \\ Time (s)} & \thead{Variance (s\$^2\$)} \\\\" >> $CODON_OUTPUT_FILE

  echo "\toprule" >> $CODON_OUTPUT_FILE

  # Loop over all Python files in the directory
  for FILE in "$DIR_PATH"/*.py; do

    # extract executable name
    EXECUTABLE_NAME=$(get_filename_without_extension "$FILE")

    BUILD_COMMAND="codon build -release --exe -o build/$EXECUTABLE_NAME $FILE"

    echo "+---------------------+"
    echo "| Build configuration : $BUILD_COMMAND"
    echo "+---------------------+"

    eval "$BUILD_COMMAND"

    times=()

    # Run the benchmark for the specified number of iterations
      for (( i=1; i<=ITERATIONS; i++ )); do

        EXECUTION_TIME=$(measure_time "build/$EXECUTABLE_NAME")

        echo "|- $EXECUTABLE_NAME: $EXECUTION_TIME"

        times+=($EXECUTION_TIME)

      done
      
      # Log the fastest time to the LaTeX table
      escaped_name=$(escape_underscores "$EXECUTABLE_NAME")

      # Calculate statistics
      r=$(echo "${times[@]}" | tr ' ' '\n' | sort -n | head -n 1)
      fastest_time=$(truncate_number "$r" 4)
      r=$(calculate_mean "${times[@]}")
      mean_time=$(truncate_number "$r" 4)
      r=$(calculate_median "${times[@]}")
      median_time=$(truncate_number "$r" 4)
      r=$(echo "${times[@]}" | tr ' ' '\n' | sort -n | tail -n 1)
      max_time=$(truncate_number "$r" 4)
      r=$(calculate_variance "${times[@]}")
      variance_time=$(truncate_number "$r" 4)

      echo "$escaped_name & $fastest_time & $mean_time & $median_time & $max_time & $variance_time \\\\" >> $CODON_OUTPUT_FILE
      echo "\midrule" >> $CODON_OUTPUT_FILE

  done

  # Finalize the LaTeX table
  echo "\end{tabular}" >> $CODON_OUTPUT_FILE
  echo "\caption{The benchmark results for Codon ($ITERATIONS iterations).}\label{tab:benchmark_results_codon}" >> $CODON_OUTPUT_FILE
  echo "\end{table}" >> $CODON_OUTPUT_FILE

  echo "+----------------+"
  echo "| FINISHED CODON |"
  echo "+----------------+"
  echo "| output written:| $CODON_OUTPUT_FILE"
  echo "+----------------+"

fi

###############
## END CODON ##
###############

####################
## END BENCHMARKS ##
####################

# clean up
rm -r ./build

echo "Benchmarking completed."
