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
    type t_customScalarField = {
      nullable: Js.Nullable.t(Js.Json.t),
      nonNullable: Js.Json.t,
    };
    type t = {customScalarField: t_customScalarField};
    type t_variables = {
      opt: Js.Nullable.t(Js.Json.t),
      req: Js.Json.t,
    };
  };
  type t_customScalarField = {
    nullable: option(Js.Json.t),
    nonNullable: Js.Json.t,
  };
  type t = {customScalarField: t_customScalarField};
  /**The GraphQL query string*/
  let query = [%raw
    "require(\"gql\")`\n  query ($opt: CustomScalar, $req: CustomScalar!)  {\n    customScalarField(argOptional: $opt, argRequired: $req)  {\n      nullable\n      nonNullable\n    }\n  }\n`"
  ];
  type t_variables = {
    opt: option(Js.Json.t),
    req: Js.Json.t,
  };
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      customScalarField: {
        let value = (value: Raw.t).customScalarField;
        (
          {
            nullable: {
              let value = (value: Raw.t_customScalarField).nullable;
              switch (Js.toOption(value)) {
              | Some(value) => Some(value)
              | None => None
              };
            },
            nonNullable: {
              let value = (value: Raw.t_customScalarField).nonNullable;
              value;
            },
          }: t_customScalarField
        );
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let customScalarField = {
        let value = (value: t).customScalarField;
        (
          {
            let nonNullable = {
              let value = (value: t_customScalarField).nonNullable;
              value;
            }
            and nullable = {
              let value = (value: t_customScalarField).nullable;
              switch (value) {
              | Some(value) => Js.Nullable.return(value)
              | None => Js.Nullable.null
              };
            };
            {nullable, nonNullable};
          }: Raw.t_customScalarField
        );
      };
      {customScalarField: customScalarField};
    }: Raw.t
  );
  let serializeVariables: t_variables => Raw.t_variables =
    inp => {
      opt:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          (inp: t_variables).opt,
        ),
      req: (a => a)((inp: t_variables).req),
    };
  let makeVariables = (~opt=?, ~req, ()) =>
    serializeVariables({opt, req}: t_variables);
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type nonrec _graphql_opt_119;
    /**Variable **$opt** has the following graphql type:

```
CustomScalar
```*/
    let _graphql_opt_119: _graphql_opt_119 = Obj.magic(0);
    type nonrec _graphql_argOptional_106;
    /**Argument **argOptional** on field **customScalarField** has the following graphql type:

```
CustomScalar
```*/
    let _graphql_argOptional_106: _graphql_argOptional_106 = Obj.magic(0);
    type nonrec _graphql_req_138;
    /**Variable **$req** has the following graphql type:

```
CustomScalar!
```*/
    let _graphql_req_138: _graphql_req_138 = Obj.magic(0);
    type nonrec _graphql_argRequired_125;
    /**Argument **argRequired** on field **customScalarField** has the following graphql type:

```
CustomScalar!
```*/
    let _graphql_argRequired_125: _graphql_argRequired_125 = Obj.magic(0);
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
