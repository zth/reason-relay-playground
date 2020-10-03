/* @generated */

module Types = {
  [@ocaml.warning "-30"];

  type response = {
    fragmentRefs:
      ReasonRelay.fragmentRefs(
        [ | `NavBarTodoItemCount_query | `LoggedInUserDisplayer_query],
      ),
  };
  type rawResponse = response;
  type variables = unit;
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"":{"f":""}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  type rawResponseRaw = responseRaw;
  let convertRawResponse = convertResponse;

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type queryRef;

module Utils = {};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| {
  "fragment": {
    "argumentDefinitions": [],
    "kind": "Fragment",
    "metadata": null,
    "name": "NavQuery",
    "selections": [
      {
        "args": null,
        "kind": "FragmentSpread",
        "name": "NavBarTodoItemCount_query"
      },
      {
        "args": null,
        "kind": "FragmentSpread",
        "name": "LoggedInUserDisplayer_query"
      }
    ],
    "type": "Query",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": [],
    "kind": "Operation",
    "name": "NavQuery",
    "selections": [
      {
        "alias": null,
        "args": null,
        "concreteType": "Statistics",
        "kind": "LinkedField",
        "name": "statistics",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "concreteType": "ValueWithTrend",
            "kind": "LinkedField",
            "name": "todoList",
            "plural": false,
            "selections": [
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "value",
                "storageKey": null
              },
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "trend",
                "storageKey": null
              }
            ],
            "storageKey": null
          }
        ],
        "storageKey": null
      },
      {
        "alias": null,
        "args": null,
        "concreteType": "User",
        "kind": "LinkedField",
        "name": "loggedInUser",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "kind": "ScalarField",
            "name": "name",
            "storageKey": null
          },
          {
            "alias": null,
            "args": null,
            "kind": "ScalarField",
            "name": "id",
            "storageKey": null
          },
          {
            "alias": null,
            "args": null,
            "kind": "ScalarField",
            "name": "isLoggedInUser",
            "storageKey": null
          },
          {
            "alias": null,
            "args": null,
            "kind": "ScalarField",
            "name": "avatarUrl",
            "storageKey": null
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "cacheID": "e0a2df8751831cd140275ad7b98b2324",
    "id": null,
    "metadata": {},
    "name": "NavQuery",
    "operationKind": "query",
    "text": "query NavQuery {\n  ...NavBarTodoItemCount_query\n  ...LoggedInUserDisplayer_query\n}\n\nfragment Avatar_user on User {\n  avatarUrl\n  name\n}\n\nfragment LoggedInUserDisplayer_query on Query {\n  loggedInUser {\n    ...UserButton_user\n    id\n  }\n}\n\nfragment NavBarTodoItemCount_query on Query {\n  statistics {\n    todoList {\n      value\n      trend\n    }\n  }\n}\n\nfragment UserButton_user on User {\n  name\n  id\n  isLoggedInUser\n  ...Avatar_user\n}\n"
  }
} |json}
];

include ReasonRelay.MakeLoadQuery({
  type variables = Types.variables;
  type loadedQueryRef = queryRef;
  type response = Types.response;
  let query = node;
  let convertVariables = Internal.convertVariables;
});
