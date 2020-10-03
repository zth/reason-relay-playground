/* @generated */

type enum_TaskPriority = pri [> | `High | `Low | `Medium | `Unprioritized];

module Types = {
  [@ocaml.warning "-30"];

  type fragment = {priority: enum_TaskPriority};
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
  ReasonRelay.fragmentRefs([> | `TaskPriorityBadge_task]) => fragmentRef =
  "%identity";

module Utils = {
  external taskPriority_toString: enum_TaskPriority => string = "%identity";
};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "TaskPriorityBadge_task",
  "selections": [
    {
      "alias": null,
      "args": null,
      "kind": "ScalarField",
      "name": "priority",
      "storageKey": null
    }
  ],
  "type": "Task",
  "abstractKey": null
} |json}
];
