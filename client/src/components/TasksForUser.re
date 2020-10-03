module UserFragment = [%relay.fragment
  {|
  fragment TasksForUser_user on User
    @refetchable(queryName: "TasksForUserPaginationQuery")
    @argumentDefinitions(
      first: { type: "Int", defaultValue: 5 }
      after: { type: "String" }
    ) {
    name
    tasks(first: $first, after: $after)
      @connection(key: "TasksForUser_user_tasks") {
      edges {
        node {
          ...TasksForUserTask_task
          id
        }
      }
    }
  }
|}
];

[@react.component]
let make = (~user) => {
  let user = UserFragment.use(user);

  let tasks = user.tasks->UserFragment.getConnectionNodes;

  <div className="w-1/2 mx-auto text-left">
    <h2 className="text-xl font-bold mt-6">
      {React.string(user.name ++ "'s tasks")}
    </h2>
    {tasks
     ->Belt.Array.map(task =>
         <div key={task.id}>
           <TasksForUserTask task={task.fragmentRefs} />
         </div>
       )
     ->React.array}
    {tasks->Belt.Array.length === 0 ? React.string("No tasks") : React.null}
  </div>;
};
