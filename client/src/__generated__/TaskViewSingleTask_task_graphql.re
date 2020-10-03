/* @generated */

module Types = {
  [@ocaml.warning "-30"];

  type fragment = {
    id: string,
    title: string,
    fragmentRefs:
      ReasonRelay.fragmentRefs(
        [
          | `TaskViewSingleTaskBody_task
          | `TaskViewSingleTaskAssignee_task
          | `TaskPriorityBadge_task
        ],
      ),
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
  ReasonRelay.fragmentRefs([> | `TaskViewSingleTask_task]) => fragmentRef =
  "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "TaskViewSingleTask_task",
  "selections": [
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
      "name": "title",
      "storageKey": null
    },
    {
      "args": null,
      "kind": "FragmentSpread",
      "name": "TaskViewSingleTaskBody_task"
    },
    {
      "args": null,
      "kind": "FragmentSpread",
      "name": "TaskViewSingleTaskAssignee_task"
    },
    {
      "args": null,
      "kind": "FragmentSpread",
      "name": "TaskPriorityBadge_task"
    }
  ],
  "type": "Task",
  "abstractKey": null
} |json}
];
