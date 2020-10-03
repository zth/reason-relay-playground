[@react.component]
let make = () => {
  <>
    <Nav />
    <div className="container w-2/3 mx-auto pt-20">
      <div
        className="w-full px-4 md:px-0 md:mt-8 mb-16 text-gray-800 leading-normal">
        <ReasonRelayRouter.RouteRenderer
          renderFallback={() => <ContentLoader.Facebook />}
          renderNotFound={_ =>
            <div> {React.string("No route matched :(")} </div>
          }
          renderPending={() => <Pending />}
          suspenseTimeout=10
        />
      </div>
    </div>
  </>;
};
