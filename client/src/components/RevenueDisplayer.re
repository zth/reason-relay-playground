module StatisticsFragment = [%relay.fragment
  {|
  fragment RevenueDisplayer_statistics on Statistics {
    totalRevenue {
      ...StatsDisplayer_valueWithTrend
    }
  }
|}
];

[@react.component]
let make = (~statistics) => {
  let data = StatisticsFragment.use(statistics);

  <StatsDisplayer
    title="Total Revenue"
    icon="fa-wallet"
    color="bg-green-600"
    valueWithTrend={data.totalRevenue.fragmentRefs}
  />;
};
