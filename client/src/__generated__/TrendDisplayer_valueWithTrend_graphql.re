/* @generated */

type enum_TrendDirection = pri [> | `Down | `Neutral | `Up];

module Types = {
  [@ocaml.warning "-30"];

  type fragment = {trend: enum_TrendDirection};
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
  ReasonRelay.fragmentRefs([> | `TrendDisplayer_valueWithTrend]) =>
  fragmentRef =
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
  "name": "TrendDisplayer_valueWithTrend",
  "selections": [
    {
      "alias": null,
      "args": null,
      "kind": "ScalarField",
      "name": "trend",
      "storageKey": null
    }
  ],
  "type": "ValueWithTrend",
  "abstractKey": null
} |json}
];
