type scalars = {
  __typename: string,
  string,
  int,
};

type dog = {
  __typename: string,
  name: string,
  barkVolume: float,
};

type oneFieldQuery = {nullableString: option(string)};
module MyQuery = [%graphql
  {|
  {
    variousScalars @ppxRecord @ppxAs(type: "scalars") {
      __typename
      string
      int
    }
  }
|}
];
module OneFieldQuery = [%graphql
  {|
  {
    variousScalars @bsRecord {
      nullableString
    }
  }
|}
];
module ExternalFragmentQuery = [%graphql
  {|
  fragment Fragment on VariousScalars @bsRecord {
    string
    int
  }
  {
    variousScalars {
      ...Fragment
    }
  }
|}
];
module InlineFragmentQuery = [%graphql
  {|
  {
    dogOrHuman {
      ...on Dog @bsRecord {
        __typename
        name
        barkVolume
      }
    }
  }
|}
];
module UnionExternalFragmentQuery = [%graphql
  {|
  fragment DogFragment on Dog @bsRecord {
    __typename
    name
    barkVolume
  }
  {
    dogOrHuman {
      ...on Dog {
        ...DogFragment
      }
    }
  }
|}
];
