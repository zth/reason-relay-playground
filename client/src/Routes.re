let dashboardRoute =
  ReasonRelayRouter.Route.make(
    ~matchUrl=
      url =>
        switch (url.path) {
        | [] => Some()
        | _ => None
        },
    ~prepare=
      () =>
        DashboardQuery_graphql.load(
          ~environment=RelayEnv.environment,
          ~variables=(),
          (),
        ),
    ~render=
      preloadedDashboardQuery =>
        <Dashboard preloadedQuery=preloadedDashboardQuery />,
  );

let viewerProfileRoute =
  ReasonRelayRouter.Route.make(
    ~matchUrl=
      url =>
        switch (url.path) {
        | ["user", "me"] => Some()
        | _ => None
        },
    ~prepare=
      () =>
        (
          ViewerProfileQuery_graphql.load(
            ~environment=RelayEnv.environment,
            ~variables=(),
            (),
          ),
          (),
        ),
    ~render=((preloaded, _)) => {<ViewerProfile preloadedUser=preloaded />},
  );

let userRoute =
  ReasonRelayRouter.Route.make(
    ~matchUrl=
      url =>
        switch (url.path) {
        | ["user", userId] => Some(userId)
        | _ => None
        },
    ~prepare=
      userId =>
        UserProfileQuery_graphql.load(
          ~environment=RelayEnv.environment,
          ~variables={id: userId},
          (),
        ),
    ~render=preloaded => <UserProfile preloadedUser=preloaded />,
  );

let taskRoute =
  ReasonRelayRouter.Route.make(
    ~matchUrl=
      url =>
        switch (url.path) {
        | ["task", taskId] => Some(taskId)
        | _ => None
        },
    ~prepare=
      taskId =>
        TaskViewQuery_graphql.load(
          ~environment=RelayEnv.environment,
          ~variables={id: taskId},
          (),
        ),
    ~render=taskViewQueryPreloaded => <TaskView taskViewQueryPreloaded />,
  );

let routerContext =
  ReasonRelayRouter.make([|
    dashboardRoute,
    viewerProfileRoute,
    userRoute,
    taskRoute,
  |]);
