module StatisticsFragment = [%relay.fragment
  {|
  fragment TaskListCountDisplayer_statistics on Statistics {
    todoList {
      ...StatsDisplayer_valueWithTrend
    }
  }
|}
];

[@react.component]
let make = (~statistics) => {
  let data = StatisticsFragment.use(statistics);

  <StatsDisplayer
    title="Task list"
    icon="fa-tasks"
    color="bg-indigo-600"
    valueWithTrend={data.todoList.fragmentRefs}
  />;
};
