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
