module TaskFragment = [%relay.fragment
  {|
  fragment TasksForUserTask_task on Task {
    ...TaskPriorityBadge_task
    id
    title
  }
|}
];

[@react.component]
let make = (~task) => {
  let task = TaskFragment.use(task);
  let (startTransition, _isPending) =
    React.useTransition(~config={timeoutMs: 200}, ());

  let navigateManually = true;

  <div className="mt-2 p-4 bg-white shadow-md">
    {navigateManually
       ? <button
           className="block"
           onClick={_ => {
             startTransition(() => {
               ReasonReactRouter.push("/task/" ++ task.id)
             })
           }}>
           <h3 className="font-bold text-md cursor-pointer">
             {React.string(task.title)}
           </h3>
         </button>
       : <ReasonRelayRouter.Link to_={"/task/" ++ task.id}>
           <h3 className="font-bold text-md cursor-pointer">
             {React.string(task.title)}
           </h3>
         </ReasonRelayRouter.Link>}
    <TaskPriorityBadge task={task.fragmentRefs} />
  </div>;
};
