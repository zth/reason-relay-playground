module StatisticsFragment = [%relay.fragment
  {|
  fragment ServerUptimeDisplayer_statistics on Statistics {
    serverUptime {
      ...StatsDisplayer_valueWithTrend
    }
  }
|}
];

[@react.component]
let make = (~statistics) => {
  let data = StatisticsFragment.use(statistics);

  <StatsDisplayer
    title="Server Uptime"
    icon="fa-server"
    color="bg-blue-600"
    valueWithTrend={data.serverUptime.fragmentRefs}
  />;
};
