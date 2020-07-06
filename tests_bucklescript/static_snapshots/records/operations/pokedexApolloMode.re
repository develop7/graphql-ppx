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
    type t_pokemon = {
      id: string,
      name: Js.Nullable.t(string),
    };
    type t = {pokemon: Js.Nullable.t(t_pokemon)};
    type t_variables = unit;
  };
  type t_pokemon = {
    id: string,
    name: option(string),
  };
  type t = {pokemon: option(t_pokemon)};
  /**The GraphQL query string*/
  let query = "query   {\npokemon(name: \"Pikachu\")  {\nid  \nname  \n}\n\n}\n";
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      pokemon: {
        let value = (value: Raw.t).pokemon;
        switch (Js.toOption(value)) {
        | Some(value) =>
          Some(
            {
              id: {
                let value = (value: Raw.t_pokemon).id;
                value;
              },
              name: {
                let value = (value: Raw.t_pokemon).name;
                switch (Js.toOption(value)) {
                | Some(value) => Some(value)
                | None => None
                };
              },
            }: t_pokemon,
          )
        | None => None
        };
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let pokemon = {
        let value = (value: t).pokemon;
        switch (value) {
        | Some(value) =>
          Js.Nullable.return(
            {
              let name = {
                let value = (value: t_pokemon).name;
                switch (value) {
                | Some(value) => Js.Nullable.return(value)
                | None => Js.Nullable.null
                };
              }
              and id = {
                let value = (value: t_pokemon).id;
                value;
              };
              {id, name};
            }: Raw.t_pokemon,
          )
        | None => Js.Nullable.null
        };
      };
      {pokemon: pokemon};
    }: Raw.t
  );
  let serializeVariables = () => ();
  let makeVariables = () => ();
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type nonrec _graphql_name_52;
    /**Argument **name** on field **pokemon** has the following graphql type:

```
String
```*/
    let _graphql_name_52: _graphql_name_52 = Obj.magic(0);
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
