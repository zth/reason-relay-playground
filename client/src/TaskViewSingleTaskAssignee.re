module TaskFragment = [%relay.fragment
  {|
  fragment TaskViewSingleTaskAssignee_task on Task {
    assignee {
      ...Avatar_user
    }
  }
|}
];

[@react.component]
let make = (~task) => {
  let task = TaskFragment.use(task);

  switch (task.assignee) {
  | Some(assignee) =>
    <div className="mr-2">
      <Avatar user={assignee.fragmentRefs} size=`small />
    </div>
  | None => React.null
  };
};
