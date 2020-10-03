module Query = [%relay.query
  {|
  query TaskViewQuery($id: ID!) {
    node(id: $id) {
      __typename
      ... on Task {
        ...TaskViewSingleTask_task
      }
    }
  }
|}
];

[@react.component]
let make = (~taskViewQueryPreloaded) => {
  let data = Query.usePreloaded(~queryRef=taskViewQueryPreloaded, ());

  switch (data.node) {
  | Some(task) => <TaskViewSingleTask task={task.fragmentRefs} />
  | None => React.string("Ooops, task not found! :(")
  };
};
