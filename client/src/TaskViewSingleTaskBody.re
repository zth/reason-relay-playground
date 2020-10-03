module TaskFragment = [%relay.fragment
  {|
  fragment TaskViewSingleTaskBody_task on Task {
    body
  }
|}
];

[@react.component]
let make = (~task) => {
  let task = TaskFragment.use(task);

  <TextContainer>
    {task.body->Belt.Option.getWithDefault("-")->React.string}
  </TextContainer>;
};
