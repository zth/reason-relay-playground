[@react.component]
let make = () => {
  let (slowdown, setSlowdown) =
    React.useState(() => SlowController.getSlowdownFromStorage());

  React.useEffect1(
    () => {
      Dom_storage.(
        setItem("slowdown", slowdown->SlowController.toString, localStorage)
      );
      None;
    },
    [|slowdown|],
  );

  <select
    className="text-sm mr-2"
    onChange={e => {
      let value = ReactEvent.Form.currentTarget(e)##value;
      setSlowdown(_ => SlowController.toValue(value));
    }}
    value={SlowController.toString(slowdown)}>
    <option value="None"> {React.string("No slowdown")} </option>
    <option value="Some"> {React.string("Some slowdown")} </option>
    <option value="Lots"> {React.string("Lots of slowdown")} </option>
  </select>;
};
