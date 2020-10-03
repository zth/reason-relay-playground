module UserFragment = [%relay.fragment
  {|
  fragment UserFriendsList_user on User
    @refetchable(queryName: "UserFriendsListPaginationQuery")
    @argumentDefinitions(
      first: { type: "Int", defaultValue: 5 }
      after: { type: "String" }
    ) {
    friends(first: $first, after: $after)
      @connection(key: "UserFriendsList_user_friends") {
      __id
      edges {
        node {
          id
          ...UserFriendsListFriend_user
        }
      }
    }
  }
|}
];

[@react.component]
let make = (~user) => {
  let user = UserFragment.usePagination(user);

  <div className="">
    <h2 className="text-xl font-bold my-6"> {React.string("Friends")} </h2>
    <div className="flex flex-row justify-center flex-wrap">
      {user.data.friends
       ->UserFragment.getConnectionNodes
       ->Belt.Array.map(friend =>
           <UserFriendsListFriend key={friend.id} user={friend.fragmentRefs} />
         )
       ->React.array}
    </div>
    {user.hasNext
       ? <div className="mt-8">
           <button
             type_="button"
             className="w-64 bg-transparent hover:bg-orange-500 text-orange-500 font-semibold hover:text-white py-2 px-4 border-2 border-orange-400 hover:border-transparent rounded"
             onClick={_ => user.loadNext(~count=5, ())->ignore}>
             {React.string(
                user.isLoadingNext ? "Loading..." : "See more friends",
              )}
           </button>
         </div>
       : React.null}
  </div>;
};
