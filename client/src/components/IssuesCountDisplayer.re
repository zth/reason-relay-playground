module StatisticsFragment = [%relay.fragment
  {|
  fragment IssuesCountDisplayer_statistics on Statistics {
    issues {
      ...StatsDisplayer_valueWithTrend
    }
  }
|}
];

[@react.component]
let make = (~statistics) => {
  let data = StatisticsFragment.use(statistics);

  <StatsDisplayer
    title="Issues"
    icon="fa-inbox"
    color="bg-red-600"
    valueWithTrend={data.issues.fragmentRefs}
  />;
};
