//
// Created by bruh on 21-9-22.
//

#ifndef CROSSOVER_PROCEDUREVISITOR_H
#define CROSSOVER_PROCEDUREVISITOR_H

#include "../../grammar/generated/TythonParserBaseVisitor.h"
#include "../ir/TythonModule.h"
#include "../../include/ir/TythonBuilder.h"
#include <any>

using namespace std;

class SourceFileVisitor : public TythonParserBaseVisitor {

private:

    TythonModule* module;
    TythonBuilder* builder;
    const std::map<std::string, const std::map<std::string, Value*>&>& external_object_symbol_table;
    std::set<std::string> imports;

public:

    SourceFileVisitor(TythonModule* bcModule, TythonBuilder* builder, const std::map<std::string, const std::map<std::string, Value*>&>& object_symbol_table) :
            module(bcModule),
            builder(builder),
            external_object_symbol_table(object_symbol_table),
            imports() {}

    std::any visitImport_statement(TythonParser::Import_statementContext *ctx) override;

    std::any visitAssign_statement(TythonParser::Assign_statementContext *ctx) override;
    std::any visitAtomic(TythonParser::AtomicContext *ctx) override;
    std::any visitConstant(TythonParser::ConstantContext *ctx) override;

    std::any visitIf_statement(TythonParser::If_statementContext *ctx) override;
    std::any visitBlock(TythonParser::BlockContext *ctx) override;
    std::any visitFunction_def(TythonParser::Function_defContext *ctx) override;

    std::any visitCall_expression(TythonParser::Call_expressionContext *ctx) override;
    std::any visitArguments(TythonParser::ArgumentsContext *ctx) override;

    Value* visitExternCallExpression(TythonParser::Call_expressionContext *ctx);
    Value* visitInternalCallExpression(TythonParser::Call_expressionContext *ctx);
    std::vector<llvm::Value*> visitExternCallParameters(TythonParser::ParametersContext *ctx);
    std::vector<llvm::Value*> visitInternalCallParameters(TythonParser::ParametersContext *ctx);

    std::any visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *ctx) override;
    std::any visitBinary_expression(TythonParser::Binary_expressionContext *ctx) override;

    llvm::Value* visitBinaryOperator(TythonParser::Binary_operatorContext *ctx, llvm::Value* lhs, llvm::Value* rhs);
    llvm::Value* visitInequalityOperator(TythonParser::Inequality_operatorContext *ctx, llvm::Value* lhs, llvm::Value* rhs);

};

#endif //CROSSOVER_PROCEDUREVISITOR_H
