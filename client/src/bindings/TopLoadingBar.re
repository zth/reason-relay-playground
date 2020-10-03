type loadingBarRef = {. [@bs.meth] "continuousStart": unit => unit};

[@bs.module "react-top-loading-bar"] [@react.component]
external make:
  (
    ~height: int,
    ~color: string,
    ~onRef: Js.Nullable.t(loadingBarRef) => unit
  ) =>
  React.element =
  "default";
