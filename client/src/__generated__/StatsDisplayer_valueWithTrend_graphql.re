/* @generated */

module Types = {
  [@ocaml.warning "-30"];

  type fragment = {
    value: float,
    fragmentRefs:
      ReasonRelay.fragmentRefs([ | `TrendDisplayer_valueWithTrend]),
  };
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"":{"f":""}}} |json}
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
  ReasonRelay.fragmentRefs([> | `StatsDisplayer_valueWithTrend]) =>
  fragmentRef =
  "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "StatsDisplayer_valueWithTrend",
  "selections": [
    {
      "alias": null,
      "args": null,
      "kind": "ScalarField",
      "name": "value",
      "storageKey": null
    },
    {
      "args": null,
      "kind": "FragmentSpread",
      "name": "TrendDisplayer_valueWithTrend"
    }
  ],
  "type": "ValueWithTrend",
  "abstractKey": null
} |json}
];
