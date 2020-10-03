module ValueWithTrendFragment = [%relay.fragment
  {|
  fragment TrendDisplayer_valueWithTrend on ValueWithTrend {
    trend
  }
|}
];

[@react.component]
let make = (~valueWithTrend) => {
  let valueWithTrend = ValueWithTrendFragment.use(valueWithTrend);

  let (textColor, icon) =
    switch (valueWithTrend.trend) {
    | `Up => ("text-green-500", "fa-caret-up")
    | `Down => ("text-red-500", "fa-caret-down")
    | _ => ("", "")
    };

  <span className=textColor> <i className={"fas " ++ icon} /> </span>;
};
