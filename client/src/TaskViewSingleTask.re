module TaskFragment = [%relay.fragment
  {|
  fragment TaskViewSingleTask_task on Task {
    id
    title
    ...TaskViewSingleTaskBody_task
    ...TaskViewSingleTaskAssignee_task
    ...TaskPriorityBadge_task
  }
|}
];

[@react.component]
let make = (~task) => {
  let task = TaskFragment.use(task);

  <div>
    <div className="flex flex-row items-center">
      <TaskViewSingleTaskAssignee task={task.fragmentRefs} />
      <h1 className="text-2xl font-bold"> {React.string(task.title)} </h1>
    </div>
    <div className="mt-2">
      <TaskPriorityBadge task={task.fragmentRefs} />
    </div>
    <TaskViewSingleTaskBody task={task.fragmentRefs} />
  </div>;
};
