[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];

module MyQuery = {
  [@ocaml.warning "-32"];
  module Raw = {
    type t_first_inner_inner = {
      .
      "__typename": string,
      "field": string,
    };
    type t_first_inner = {
      .
      "__typename": string,
      "inner": Js.Nullable.t(t_first_inner_inner),
    };
    type t_first = {
      .
      "__typename": string,
      "inner": Js.Nullable.t(t_first_inner),
    };
    type t = {. "first": t_first};
    type t_variables = unit;
  };
  type t_first_inner_inner = {
    .
    "__typename": string,
    "field": string,
  };
  type t_first_inner = {
    .
    "__typename": string,
    "inner": option(t_first_inner_inner),
  };
  type t_first = {
    .
    "__typename": string,
    "inner": option(t_first_inner),
  };
  type t = {. "first": t_first};
  /**The GraphQL query string*/
  let query = "query   {\nfirst: nestedObject  {\n__typename  \ninner  {\n__typename  \ninner  {\n__typename  \nfield  \n}\n\n}\n\n}\n\n}\n";
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let first = {
      let value = value##first;
      let inner = {
        let value = value##inner;
        switch (Js.toOption(value)) {
        | Some(value) =>
          Some(
            {
              let inner = {
                let value = value##inner;
                switch (Js.toOption(value)) {
                | Some(value) =>
                  Some(
                    {
                      let field = {
                        let value = value##field;
                        value;
                      }
                      and __typename = {
                        let value = value##__typename;
                        value;
                      };
                      {"__typename": __typename, "field": field};
                    },
                  )
                | None => None
                };
              }
              and __typename = {
                let value = value##__typename;
                value;
              };
              {"__typename": __typename, "inner": inner};
            },
          )
        | None => None
        };
      }
      and __typename = {
        let value = value##__typename;
        value;
      };
      {"__typename": __typename, "inner": inner};
    };
    {"first": first};
  };
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let first = {
      let value = value##first;
      let inner = {
        let value = value##inner;
        switch (value) {
        | Some(value) =>
          Js.Nullable.return(
            {
              let inner = {
                let value = value##inner;
                switch (value) {
                | Some(value) =>
                  Js.Nullable.return(
                    {
                      let field = {
                        let value = value##field;
                        value;
                      }
                      and __typename = {
                        let value = value##__typename;
                        value;
                      };
                      {"__typename": __typename, "field": field};
                    },
                  )
                | None => Js.Nullable.null
                };
              }
              and __typename = {
                let value = value##__typename;
                value;
              };
              {"__typename": __typename, "inner": inner};
            },
          )
        | None => Js.Nullable.null
        };
      }
      and __typename = {
        let value = value##__typename;
        value;
      };
      {"__typename": __typename, "inner": inner};
    };
    {"first": first};
  };
  let serializeVariables = () => ();
  let makeVariables = () => ();
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
