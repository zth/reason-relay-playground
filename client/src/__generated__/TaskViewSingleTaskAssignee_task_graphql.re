/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type fragment_assignee = {
    fragmentRefs: ReasonRelay.fragmentRefs([ | `Avatar_user]),
  };

  type fragment = {assignee: option(fragment_assignee)};
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"assignee":{"n":"","f":""}}} |json}
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
  ReasonRelay.fragmentRefs([> | `TaskViewSingleTaskAssignee_task]) =>
  fragmentRef =
  "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "TaskViewSingleTaskAssignee_task",
  "selections": [
    {
      "alias": null,
      "args": null,
      "concreteType": "User",
      "kind": "LinkedField",
      "name": "assignee",
      "plural": false,
      "selections": [
        {
          "args": null,
          "kind": "FragmentSpread",
          "name": "Avatar_user"
        }
      ],
      "storageKey": null
    }
  ],
  "type": "Task",
  "abstractKey": null
} |json}
];
