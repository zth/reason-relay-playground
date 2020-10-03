exception Graphql_error(string);

let fetchQuery: ReasonRelay.Network.fetchFunctionObservable =
  (operation, variables, _cacheConfig) =>
    ReasonRelay.Observable.make(sink => {
      FetchMultipart.(
        fetch(
          "http://localhost:4000/graphql",
          {
            _method: "POST",
            headers:
              Js.Dict.fromList([
                ("content-type", "application/json"),
                ("x-slowdown", SlowController.getSlowdown()),
              ]),
            body:
              {"query": operation.text, "variables": variables}
              ->Js.Json.stringifyAny
              ->Belt.Option.getWithDefault(""),
            onNext: parts => sink.next(parts),
            onError: err => sink.error(err),
            onComplete: () => sink.complete(),
          },
        )
      );

      None;
    });

let network =
  ReasonRelay.Network.makeObservableBased(~observableFunction=fetchQuery, ());

let environment =
  ReasonRelay.Environment.make(
    ~network,
    ~store=
      ReasonRelay.Store.make(
        ~source=ReasonRelay.RecordSource.make(),
        ~gcReleaseBufferSize=50,
        (),
      ),
    (),
  );
