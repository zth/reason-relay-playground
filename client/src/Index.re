[%bs.raw {|require("./assets/style.css")|}];

Utils.renderConcurrentRootAtId(
  "app",
  <ReasonRelay.Context.Provider environment=RelayEnv.environment>
    <React.Suspense fallback={<ContentLoader.Facebook />}>
      <ReasonRelayRouter.Provider value={Some(Routes.routerContext)}>
        <Main />
      </ReasonRelayRouter.Provider>
    </React.Suspense>
  </ReasonRelay.Context.Provider>,
);
