module QueryFragment = [%relay.fragment
  {|
  fragment NavBarTodoItemCount_query on Query {
    statistics {
      todoList {
        value
        trend
      }
    }
  }
|}
];

[@react.component]
let make = (~query) => {
  let query = QueryFragment.use(query);

  <div className="text-xs text-gray-700 align-text-bottom">
    {React.string(
       "Tasks: " ++ query.statistics.todoList.value->Js.Float.toString,
     )}
  </div>;
};
