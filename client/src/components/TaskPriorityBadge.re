module TaskFragment = [%relay.fragment
  {|
  fragment TaskPriorityBadge_task on Task {
    priority
  }
|}
];

[@react.component]
let make = (~task) => {
  let task = TaskFragment.use(task);

  <div
    className={
      "rounded-md px-2 py-1 text-xs uppercase font-semibold text-white inline-block "
      ++ (
        switch (task.priority) {
        | `High => "bg-red-600"
        | `Medium => "bg-orange-600"
        | `Low => "bg-blue-600"
        | `Unprioritized => "bg-gray-600"
        | _ => ""
        }
      )
    }>
    {React.string(
       switch (task.priority) {
       | `High => "High"
       | `Medium => "Medium"
       | `Low => "Low"
       | `Unprioritized => "No priority"
       | _ => "-"
       },
     )}
  </div>;
};
