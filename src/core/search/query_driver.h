// Copyright 2023, DragonflyDB authors.  All rights reserved.
// See LICENSE for licensing terms.
//

#pragma once

#include <memory>

#include "core/search/ast_expr.h"
#include "core/search/parser.hh"
#include "core/search/scanner.h"

namespace dfly {

namespace search {

class QueryDriver {
 public:
  QueryDriver();
  ~QueryDriver();

  Scanner* scanner() {
    return scanner_.get();
  }

  void SetInput(std::string str) {
    cur_str_ = std::move(str);
    scanner()->in(cur_str_);
  }

  Parser::symbol_type Lex() {
    return scanner()->Lex();
  }

  Parser::location_type location;

  void Add(AstExpr) {
  }

 private:
  std::string cur_str_;
  std::unique_ptr<Scanner> scanner_;
};

}  // namespace search
}  // namespace dfly
