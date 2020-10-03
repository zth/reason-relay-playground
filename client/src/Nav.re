module Query = [%relay.query
  {|
  query NavQuery {
    ...NavBarTodoItemCount_query
    ...LoggedInUserDisplayer_query
  }
|}
];

[@react.component]
let make = () => {
  let query = Query.use(~variables=(), ~renderPolicy=Partial, ());

  <nav id="header" className="bg-white fixed w-full z-10 top-0 shadow">
    <div
      className="w-full container mx-auto flex flex-wrap items-center mt-0 pt-3 pb-3 md:pb-0">
      <div className="w-1/2 pl-2 md:pl-0 flex align-bottom">
        <ReasonRelayRouter.Link
          className="text-gray-900 text-base xl:text-xl no-underline hover:no-underline font-bold"
          to_="/">
          <i className="fas fa-sun text-orange-600 pr-3" />
          {j|ReasonRelay Dashboard|j}->React.string
        </ReasonRelayRouter.Link>
        <div className="ml-2 mt-1">
          <React.Suspense fallback={<div />}>
            <NavBarTodoItemCount query={query.fragmentRefs} />
          </React.Suspense>
        </div>
      </div>
      <div className="w-1/2 pr-0">
        <div className="relative inline-block float-right">
          <div className="relative text-sm w-40">
            <React.Suspense fallback={<LoggedInUserDisplayerLoading />}>
              <LoggedInUserDisplayer query={query.fragmentRefs} />
            </React.Suspense>
          </div>
        </div>
      </div>
      <div
        className="w-full flex-grow lg:flex lg:items-center lg:w-auto hidden mt-2 lg:mt-0 bg-white z-20"
        id="nav-content">
        <ul className="list-reset lg:flex flex-1 items-center px-4 md:px-0">
          <NavItem title="Dashboard" to_="/" />
        </ul>
        <div className="pull-right w-40"> <SlowControllerSelector /> </div>
      </div>
    </div>
  </nav>;
};
