/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type fragment_issues = {
    fragmentRefs:
      ReasonRelay.fragmentRefs([ | `StatsDisplayer_valueWithTrend]),
  };

  type fragment = {issues: fragment_issues};
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"issues":{"f":""}}} |json}
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
  ReasonRelay.fragmentRefs([> | `IssuesCountDisplayer_statistics]) =>
  fragmentRef =
  "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "IssuesCountDisplayer_statistics",
  "selections": [
    {
      "alias": null,
      "args": null,
      "concreteType": "ValueWithTrend",
      "kind": "LinkedField",
      "name": "issues",
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
