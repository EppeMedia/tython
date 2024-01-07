//
// Created by bruh on 21-9-22.
//

#ifndef CROSSOVER_PROCEDUREVISITOR_H
#define CROSSOVER_PROCEDUREVISITOR_H

#include "../parser/TythonBaseVisitor.h"
#include "../ir/TythonModule.h"
#include "../../include/ir/TythonBuilder.h"
#include <any>

using namespace std;

class SourceFileVisitor : public TythonBaseVisitor {

private:

    TythonModule* module;
    TythonBuilder* builder;

public:

    SourceFileVisitor(TythonModule* bcModule, TythonBuilder* builder) :
            module(bcModule),
            builder(builder) {}

    std::any visitAssign_statement(TythonParser::Assign_statementContext *ctx) override;
    std::any visitAtomic(TythonParser::AtomicContext *ctx) override;
    std::any visitConstant(TythonParser::ConstantContext *ctx) override;

    std::any visitIf_statement(TythonParser::If_statementContext *ctx) override;
    std::any visitBlock(TythonParser::BlockContext *ctx) override;
    std::any visitFunction(TythonParser::FunctionContext *ctx) override;

    std::any visitCall_expression(TythonParser::Call_expressionContext *ctx) override;
    std::any visitParameters(TythonParser::ParametersContext *ctx) override;
    std::any visitArguments(TythonParser::ArgumentsContext *ctx) override;

};

#endif //CROSSOVER_PROCEDUREVISITOR_H
