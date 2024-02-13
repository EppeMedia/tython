//
// Created by bruh on 21-9-22.
//

#ifndef CROSSOVER_PROCEDUREVISITOR_H
#define CROSSOVER_PROCEDUREVISITOR_H

#include "../../src/grammar/generated/TythonParserBaseVisitor.h"
#include "../ir/TythonModule.h"
#include "../../include/ir/TythonBuilder.h"
#include <any>

using namespace std;

class SourceFileVisitor : public TythonParserBaseVisitor {

private:

    TythonModule* module;
    TythonBuilder* builder;
    const std::map<std::string, const std::map<std::string, llvm::Function*>*>& external_object_symbol_table;
    std::set<std::string> imports;

public:

    SourceFileVisitor(TythonModule* tythonModule, TythonBuilder* builder, const std::map<std::string, const std::map<std::string, llvm::Function*>*>& object_symbol_table) :
            module(tythonModule),
            builder(builder),
            external_object_symbol_table(object_symbol_table),
            imports() {}

    std::any visitImport_statement(TythonParser::Import_statementContext *ctx) override;

    std::any visitAssign_statement(TythonParser::Assign_statementContext *ctx) override;

    std::any visitLbl_identifier(TythonParser::Lbl_identifierContext *ctx) override;
    std::any visitLbl_key_access(TythonParser::Lbl_key_accessContext *ctx) override;

    std::any visitLiteral(TythonParser::LiteralContext *ctx) override;
    std::any visitDict_lit(TythonParser::Dict_litContext *ctx) override;

    std::any visitIf_statement(TythonParser::If_statementContext *ctx) override;
    std::any visitBlock(TythonParser::BlockContext *ctx) override;
    std::any visitFunction_def(TythonParser::Function_defContext *ctx) override;

    std::any visitCall_expression(TythonParser::Call_expressionContext *ctx) override;
    std::any visitArguments(TythonParser::ArgumentsContext *ctx) override;

    llvm::Value* visitExternCallExpression(TythonParser::Call_expressionContext *ctx);
    llvm::Value* visitInternalCallExpression(TythonParser::Call_expressionContext *ctx);
    std::vector<llvm::Value*> visitExternCallParameters(TythonParser::ParametersContext *ctx);
    std::vector<llvm::Value*> visitInternalCallParameters(TythonParser::ParametersContext *ctx);

    std::any visitBinary_expression(TythonParser::Binary_expressionContext *ctx) override;

    llvm::Value* visitBinaryOperator(TythonParser::Binary_operatorContext *ctx, llvm::Value* lhs, llvm::Value* rhs);
    llvm::Value* visitInequalityOperator(TythonParser::Inequality_operatorContext *ctx, llvm::Value* lhs, llvm::Value* rhs);

};

#endif //CROSSOVER_PROCEDUREVISITOR_H
