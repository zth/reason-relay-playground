/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type fragment_totalUsers = {
    fragmentRefs:
      ReasonRelay.fragmentRefs([ | `StatsDisplayer_valueWithTrend]),
  };

  type fragment = {totalUsers: fragment_totalUsers};
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"totalUsers":{"f":""}}} |json}
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
  ReasonRelay.fragmentRefs([> | `TotalUsersDisplayer_statistics]) =>
  fragmentRef =
  "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "TotalUsersDisplayer_statistics",
  "selections": [
    {
      "alias": null,
      "args": null,
      "concreteType": "ValueWithTrend",
      "kind": "LinkedField",
      "name": "totalUsers",
      "plural": false,
      "selections": [
        {
          "args": null,
          "kind": "FragmentSpread",
          "name": "StatsDisplayer_valueWithTrend"
        }
      ],
      "storageKey": null
    }
  ],
  "type": "Statistics",
  "abstractKey": null
} |json}
];
