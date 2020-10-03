/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type response_statistics = {
    fragmentRefs:
      ReasonRelay.fragmentRefs(
        [
          | `RevenueDisplayer_statistics
          | `TotalUsersDisplayer_statistics
          | `NewUsersDisplayer_statistics
          | `ServerUptimeDisplayer_statistics
          | `TaskListCountDisplayer_statistics
          | `IssuesCountDisplayer_statistics
        ],
      ),
  };

  type response = {statistics: response_statistics};
  type rawResponse = response;
  type variables = unit;
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"statistics":{"f":""}}} |json}
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
  {json| (function(){
var v0 = [
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
];
return {
  "fragment": {
    "argumentDefinitions": [],
    "kind": "Fragment",
    "metadata": null,
    "name": "DashboardQuery",
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
            "kind": "Defer",
            "selections": [
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "RevenueDisplayer_statistics"
              }
            ]
          },
          {
            "kind": "Defer",
            "selections": [
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "TotalUsersDisplayer_statistics"
              }
            ]
          },
          {
            "kind": "Defer",
            "selections": [
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "NewUsersDisplayer_statistics"
              }
            ]
          },
          {
            "kind": "Defer",
            "selections": [
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "ServerUptimeDisplayer_statistics"
              }
            ]
          },
          {
            "kind": "Defer",
            "selections": [
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "TaskListCountDisplayer_statistics"
              }
            ]
          },
          {
            "kind": "Defer",
            "selections": [
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "IssuesCountDisplayer_statistics"
              }
            ]
          }
        ],
        "storageKey": null
      }
    ],
    "type": "Query",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": [],
    "kind": "Operation",
    "name": "DashboardQuery",
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
            "if": null,
            "kind": "Defer",
            "label": "DashboardQuery$defer$RevenueDisplayer_statistics",
            "selections": [
              {
                "alias": null,
                "args": null,
                "concreteType": "ValueWithTrend",
                "kind": "LinkedField",
                "name": "totalRevenue",
                "plural": false,
                "selections": (v0/*: any*/),
                "storageKey": null
              }
            ]
          },
          {
            "if": null,
            "kind": "Defer",
            "label": "DashboardQuery$defer$TotalUsersDisplayer_statistics",
            "selections": [
              {
                "alias": null,
                "args": null,
                "concreteType": "ValueWithTrend",
                "kind": "LinkedField",
                "name": "totalUsers",
                "plural": false,
                "selections": (v0/*: any*/),
                "storageKey": null
              }
            ]
          },
          {
            "if": null,
            "kind": "Defer",
            "label": "DashboardQuery$defer$NewUsersDisplayer_statistics",
            "selections": [
              {
                "alias": null,
                "args": null,
                "concreteType": "ValueWithTrend",
                "kind": "LinkedField",
                "name": "newUsers",
                "plural": false,
                "selections": (v0/*: any*/),
                "storageKey": null
              }
            ]
          },
          {
            "if": null,
            "kind": "Defer",
            "label": "DashboardQuery$defer$ServerUptimeDisplayer_statistics",
            "selections": [
              {
                "alias": null,
                "args": null,
                "concreteType": "ValueWithTrend",
                "kind": "LinkedField",
                "name": "serverUptime",
                "plural": false,
                "selections": (v0/*: any*/),
                "storageKey": null
              }
            ]
          },
          {
            "if": null,
            "kind": "Defer",
            "label": "DashboardQuery$defer$TaskListCountDisplayer_statistics",
            "selections": [
              {
                "alias": null,
                "args": null,
                "concreteType": "ValueWithTrend",
                "kind": "LinkedField",
                "name": "todoList",
                "plural": false,
                "selections": (v0/*: any*/),
                "storageKey": null
              }
            ]
          },
          {
            "if": null,
            "kind": "Defer",
            "label": "DashboardQuery$defer$IssuesCountDisplayer_statistics",
            "selections": [
              {
                "alias": null,
                "args": null,
                "concreteType": "ValueWithTrend",
                "kind": "LinkedField",
                "name": "issues",
                "plural": false,
                "selections": (v0/*: any*/),
                "storageKey": null
              }
            ]
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "cacheID": "9a84d90b91dde7fc656450e821d724b0",
    "id": null,
    "metadata": {},
    "name": "DashboardQuery",
    "operationKind": "query",
    "text": "query DashboardQuery {\n  statistics {\n    ...RevenueDisplayer_statistics @defer(label: \"DashboardQuery$defer$RevenueDisplayer_statistics\")\n    ...TotalUsersDisplayer_statistics @defer(label: \"DashboardQuery$defer$TotalUsersDisplayer_statistics\")\n    ...NewUsersDisplayer_statistics @defer(label: \"DashboardQuery$defer$NewUsersDisplayer_statistics\")\n    ...ServerUptimeDisplayer_statistics @defer(label: \"DashboardQuery$defer$ServerUptimeDisplayer_statistics\")\n    ...TaskListCountDisplayer_statistics @defer(label: \"DashboardQuery$defer$TaskListCountDisplayer_statistics\")\n    ...IssuesCountDisplayer_statistics @defer(label: \"DashboardQuery$defer$IssuesCountDisplayer_statistics\")\n  }\n}\n\nfragment IssuesCountDisplayer_statistics on Statistics {\n  issues {\n    ...StatsDisplayer_valueWithTrend\n  }\n}\n\nfragment NewUsersDisplayer_statistics on Statistics {\n  newUsers {\n    ...StatsDisplayer_valueWithTrend\n  }\n}\n\nfragment RevenueDisplayer_statistics on Statistics {\n  totalRevenue {\n    ...StatsDisplayer_valueWithTrend\n  }\n}\n\nfragment ServerUptimeDisplayer_statistics on Statistics {\n  serverUptime {\n    ...StatsDisplayer_valueWithTrend\n  }\n}\n\nfragment StatsDisplayer_valueWithTrend on ValueWithTrend {\n  value\n  ...TrendDisplayer_valueWithTrend\n}\n\nfragment TaskListCountDisplayer_statistics on Statistics {\n  todoList {\n    ...StatsDisplayer_valueWithTrend\n  }\n}\n\nfragment TotalUsersDisplayer_statistics on Statistics {\n  totalUsers {\n    ...StatsDisplayer_valueWithTrend\n  }\n}\n\nfragment TrendDisplayer_valueWithTrend on ValueWithTrend {\n  trend\n}\n"
  }
};
})() |json}
];

include ReasonRelay.MakeLoadQuery({
  type variables = Types.variables;
  type loadedQueryRef = queryRef;
  type response = Types.response;
  let query = node;
  let convertVariables = Internal.convertVariables;
});
