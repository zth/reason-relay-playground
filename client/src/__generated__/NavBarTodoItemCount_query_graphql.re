/* @generated */

type enum_TrendDirection = pri [> | `Down | `Neutral | `Up];

module Types = {
  [@ocaml.warning "-30"];
  type fragment_statistics = {todoList: fragment_statistics_todoList}
  and fragment_statistics_todoList = {
    value: float,
    trend: enum_TrendDirection,
  };

  type fragment = {statistics: fragment_statistics};
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let fragmentConverterMap = ();
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
external getFragmentRef:
  ReasonRelay.fragmentRefs([> | `NavBarTodoItemCount_query]) => fragmentRef =
  "%identity";

module Utils = {
  external trendDirection_toString: enum_TrendDirection => string =
    "%identity";
};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "NavBarTodoItemCount_query",
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
    }
  ],
  "type": "Query",
  "abstractKey": null
} |json}
];
