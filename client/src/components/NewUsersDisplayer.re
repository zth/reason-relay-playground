module StatisticsFragment = [%relay.fragment
  {|
  fragment NewUsersDisplayer_statistics on Statistics {
    newUsers {
      ...StatsDisplayer_valueWithTrend
    }
  }
|}
];

[@react.component]
let make = (~statistics) => {
  let data = StatisticsFragment.use(statistics);

  <StatsDisplayer
    title="New Users"
    icon="fa-user-plus"
    color="bg-yellow-600"
    valueWithTrend={data.newUsers.fragmentRefs}
  />;
};
