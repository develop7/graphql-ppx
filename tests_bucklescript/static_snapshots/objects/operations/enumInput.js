// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


var Raw = { };

var query = "query ($arg: SampleField!)  {\nenumInput(arg: $arg)  \n}\n";

function parse(value) {
  return {
          enumInput: value.enumInput
        };
}

function serialize(value) {
  return {
          enumInput: value.enumInput
        };
}

function serializeVariables(inp) {
  var a = inp.arg;
  return {
          arg: a !== 225952583 ? (
              a >= 382368628 ? "SECOND" : "FIRST"
            ) : "THIRD"
        };
}

function makeVariables(arg, param) {
  return serializeVariables({
              arg: arg
            });
}

var Z__INTERNAL = {
  _graphql_SampleField_47: 0,
  graphql_module: 0
};

var MyQuery$prime = {
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  Z__INTERNAL: Z__INTERNAL
};

var MyQuery = {
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  Z__INTERNAL: Z__INTERNAL,
  self: MyQuery$prime
};

exports.MyQuery$prime = MyQuery$prime;
exports.MyQuery = MyQuery;
/* No side effect */