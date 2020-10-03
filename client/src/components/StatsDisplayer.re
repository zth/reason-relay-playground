module ValueWithTrendFragment = [%relay.fragment
  {|
  fragment StatsDisplayer_valueWithTrend on ValueWithTrend {
    value
    ...TrendDisplayer_valueWithTrend
  }
|}
];

module StatsDisplayerStructure = {
  [@react.component]
  let make = (~content) => {
    <div className="w-full md:w-1/2 xl:w-1/3 p-3">
      <div
        className="bg-white border rounded shadow p-2"
        style={ReactDOMRe.Style.make(~height="90px", ())}>
        content
      </div>
    </div>;
  };
};

module Loader = {
  [@react.component]
  let make = () => {
    <StatsDisplayerStructure
      content={
        <ContentLoader.Default>
          <rect x="0" y="0" rx="5" ry="5" width="70" height="70" />
        </ContentLoader.Default>
      }
    />;
  };
};

[@react.component]
let make = (~title, ~icon, ~color, ~valueWithTrend) => {
  let data = ValueWithTrendFragment.use(valueWithTrend);

  <StatsDisplayerStructure
    content={
      <div className="flex flex-row items-center">
        <div className="flex-shrink pr-4">
          <div className={"rounded p-3 " ++ color}>
            <i className={"fas fa-2x fa-fw fa-inverse " ++ icon} />
          </div>
        </div>
        <div className="flex-1 text-right md:text-center">
          <h5 className="font-bold uppercase text-gray-500">
            {React.string(title)}
          </h5>
          <h3 className="font-bold text-3xl">
            {data.value->Js.Float.toString->React.string}
            <TrendDisplayer valueWithTrend={data.fragmentRefs} />
          </h3>
        </div>
      </div>
    }
  />;
};
