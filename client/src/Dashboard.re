module Query = [%relay.query
  {|
  query DashboardQuery {
    statistics {
      ...RevenueDisplayer_statistics @defer
      ...TotalUsersDisplayer_statistics @defer
      ...NewUsersDisplayer_statistics @defer
      ...ServerUptimeDisplayer_statistics @defer
      ...TaskListCountDisplayer_statistics @defer
      ...IssuesCountDisplayer_statistics @defer
    }
  }
|}
];

[@react.component]
let make = (~preloadedQuery) => {
  let queryData =
    Query.usePreloaded(~queryRef=preloadedQuery, ~renderPolicy=Partial, ());

  <div className="flex flex-wrap">
    <React.SuspenseList revealOrder=`backwards>
      <React.Suspense fallback={<StatsDisplayer.Loader />}>
        <RevenueDisplayer statistics={queryData.statistics.fragmentRefs} />
      </React.Suspense>
      <React.Suspense fallback={<StatsDisplayer.Loader />}>
        <TotalUsersDisplayer statistics={queryData.statistics.fragmentRefs} />
      </React.Suspense>
      <React.Suspense fallback={<StatsDisplayer.Loader />}>
        <NewUsersDisplayer statistics={queryData.statistics.fragmentRefs} />
      </React.Suspense>
      <React.Suspense fallback={<StatsDisplayer.Loader />}>
        <ServerUptimeDisplayer
          statistics={queryData.statistics.fragmentRefs}
        />
      </React.Suspense>
      <React.Suspense fallback={<StatsDisplayer.Loader />}>
        <TaskListCountDisplayer
          statistics={queryData.statistics.fragmentRefs}
        />
      </React.Suspense>
      <React.Suspense fallback={<StatsDisplayer.Loader />}>
        <IssuesCountDisplayer statistics={queryData.statistics.fragmentRefs} />
      </React.Suspense>
    </React.SuspenseList>
  </div>;
};
