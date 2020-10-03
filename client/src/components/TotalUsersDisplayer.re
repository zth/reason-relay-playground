module StatisticsFragment = [%relay.fragment
  {|
  fragment TotalUsersDisplayer_statistics on Statistics {
    totalUsers {
      ...StatsDisplayer_valueWithTrend
    }
  }
|}
];

[@react.component]
let make = (~statistics) => {
  let data = StatisticsFragment.use(statistics);

  <StatsDisplayer
    title="Total users"
    icon="fa-users"
    color="bg-orange-600"
    valueWithTrend={data.totalUsers.fragmentRefs}
  />;
};
