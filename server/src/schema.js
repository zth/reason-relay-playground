const {
  GraphQLSchema,
  GraphQLObjectType,
  GraphQLNonNull,
  GraphQLFloat,
  GraphQLEnumType,
  GraphQLString,
  GraphQLID,
  GraphQLScalarType,
  Kind,
  GraphQLBoolean,
} = require("graphql");
const {
  connectionFromArray,
  fromGlobalId,
  toGlobalId,
  nodeDefinitions,
  connectionDefinitions,
  connectionArgs,
} = require("graphql-relay");

const GraphQLDateTime = require("graphql-type-datetime");
const { slowdownValue } = require("./slowdownValue");

const urlScalar = new GraphQLScalarType({
  name: "URL",
  parseLiteral(a) {
    if (a.kind === Kind.STRING) {
      return String(a.value);
    }

    return null;
  },
  serialize: (a) => a,
  parseValue: (a) => a,
});

const { nodeField, nodeInterface } = nodeDefinitions(
  (nodeId, ctx) => {
    const { id, type } = fromGlobalId(nodeId);

    switch (type) {
      case "User":
        return users[id] || null;
      case "Task":
        return slowdownValue(
          ctx.slowdown,
          tasks.find((t) => t.id === id) || null
        );
      default:
        return null;
    }
  },
  (o) => {
    switch (o.type) {
      case "User":
        return user;
      case "Task":
        return task;
      default:
        return null;
    }
  }
);

/**
 * User
 */

const user = new GraphQLObjectType({
  name: "User",
  interfaces: () => [nodeInterface],
  fields: () => ({
    id: {
      type: new GraphQLNonNull(GraphQLID),
      resolve: (u) => toGlobalId("User", u.id),
    },
    avatarUrl: {
      type: new GraphQLNonNull(urlScalar),
    },
    name: {
      type: new GraphQLNonNull(GraphQLString),
    },
    description: {
      type: GraphQLString,
    },
    lastSeenAt: {
      type: new GraphQLNonNull(GraphQLDateTime),
    },
    isLoggedInUser: {
      type: new GraphQLNonNull(GraphQLBoolean),
      resolve(u) {
        return u.id === loggedInUser.id;
      },
    },
    friends: {
      type: new GraphQLNonNull(userConnection),
      args: connectionArgs,
      resolve(u, args, ctx) {
        return slowdownValue(
          ctx.slowdown,
          connectionFromArray(
            Object.values(users).filter((usr) =>
              usr.friendsWith.includes(u.id)
            ),
            args
          )
        );
      },
    },
    tasks: {
      type: new GraphQLNonNull(taskConnection),
      args: {
        ...connectionArgs,
        priority: {
          type: taskPriorityEnum,
        },
      },
      resolve(u, args, ctx) {
        return slowdownValue(
          ctx.slowdown,
          connectionFromArray(
            tasks.filter((t) => {
              if (t.assignee !== u.id) {
                return false;
              }

              if (args.priority != null && t.priority !== args.priority) {
                return false;
              }

              return true;
            }),
            args
          )
        );
      },
    },
  }),
});

const { connectionType: userConnection } = connectionDefinitions({
  nodeType: user,
  name: "User",
});

const loggedInUser = {
  type: "User",
  id: "user-1",
  name: "First User",
  avatarUrl: "https://i.pravatar.cc/150?img=63",
  description: `Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.`,
  friendsWith: ["user-2", "user-3", "user-4", "user-5", "user-6", "user-7"],
};

const users = [
  loggedInUser,
  {
    type: "User",
    id: "user-2",
    name: "Second User",
    avatarUrl: "https://i.pravatar.cc/150?img=2",
    description: `Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.`,
    friendsWith: ["user-1"],
  },
  {
    type: "User",
    id: "user-3",
    name: "Third User",
    avatarUrl: "https://i.pravatar.cc/150?img=7",
    description: `Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.`,
    friendsWith: ["user-1"],
  },
  {
    type: "User",
    id: "user-4",
    name: "Fourth User",
    avatarUrl: "https://i.pravatar.cc/150?img=16",
    description: null,
    friendsWith: ["user-1"],
  },
  {
    type: "User",
    id: "user-5",
    name: "Fifth User",
    avatarUrl: "https://i.pravatar.cc/150?img=22",
    description: null,
    friendsWith: ["user-1"],
  },
  {
    type: "User",
    id: "user-6",
    name: "Sixth User",
    avatarUrl: "https://i.pravatar.cc/150?img=25",
    description: null,
    friendsWith: ["user-1"],
  },
  {
    type: "User",
    id: "user-7",
    name: "Seventh User",
    avatarUrl: "https://i.pravatar.cc/150?img=20",
    description: null,
    friendsWith: ["user-1"],
  },
].reduce((acc, curr) => {
  acc[curr.id] = curr;
  return acc;
}, {});

/**
 * Task
 */

const taskPriorityEnum = new GraphQLEnumType({
  name: "TaskPriority",
  values: {
    High: {
      value: "High",
    },
    Medium: {
      value: "Medium",
    },
    Low: {
      value: "Low",
    },
    Unprioritized: {
      value: "Unprioritized",
    },
  },
});

const task = new GraphQLObjectType({
  name: "Task",
  interfaces: () => [nodeInterface],
  fields: () => ({
    id: {
      type: new GraphQLNonNull(GraphQLID),
      resolve: (t) => toGlobalId("Task", t.id),
    },
    createdAt: {
      type: new GraphQLNonNull(GraphQLDateTime),
    },
    title: {
      type: new GraphQLNonNull(GraphQLString),
    },
    priority: {
      type: new GraphQLNonNull(taskPriorityEnum),
    },
    body: {
      type: GraphQLString,
    },
    assignee: {
      type: user,
      resolve(o, _, ctx) {
        return slowdownValue(ctx.slowdown, users[o.assignee] || null);
      },
    },
  }),
});

const {
  connectionType: taskConnection,
  edgeType: taskEdge,
} = connectionDefinitions({
  nodeType: task,
  name: "Task",
});

const tasks = [
  {
    type: "Task",
    id: "task-1",
    createdAt: new Date(2020, 5, 22),
    title: "Reset all servers",
    priority: "High",
    assignee: "user-2",
    body: "We must reset all servers. Full reset please. Something's wrong.",
  },
  {
    type: "Task",
    id: "task-2",
    createdAt: new Date(2020, 5, 29, 10, 15),
    title: "Reduce number of requests",
    priority: "Unprioritized",
    assignee: "user-2",
    body: `Ideas:
    1) Ban users making requests
    2) Evict paying customers to reduce load
    3) Rewrite everything in assembly`,
  },
  {
    type: "Task",
    id: "task-3",
    createdAt: new Date(2020, 6, 1, 16),
    title: "Investigate load",
    priority: "Medium",
    assignee: "user-2",
    body: "The load is way too high. Can't take it.",
  },
  {
    type: "Task",
    id: "task-4",
    createdAt: new Date(2020, 6, 3, 9, 58),
    title: "Clean up service #1",
    priority: "Unprioritized",
    assignee: "user-3",
  },
];

let taskId = 4;

/**
 * Value with trend
 */

const trendEnum = new GraphQLEnumType({
  name: "TrendDirection",
  values: {
    Up: {
      value: "Up",
    },
    Neutral: {
      value: "Neutral",
    },
    Down: {
      value: "Down",
    },
  },
});

const valueWithTrend = new GraphQLObjectType({
  name: "ValueWithTrend",
  fields: () => ({
    value: {
      type: new GraphQLNonNull(GraphQLFloat),
    },
    trend: {
      type: new GraphQLNonNull(trendEnum),
    },
  }),
});

/**
 * Stats
 */

const stats = new GraphQLObjectType({
  name: "Statistics",
  fields: () => ({
    totalRevenue: {
      type: new GraphQLNonNull(valueWithTrend),
      resolve(_o, _a, ctx) {
        return slowdownValue(ctx.slowdown, {
          value: 3249,
          trend: "Down",
        });
      },
    },
    totalUsers: {
      type: new GraphQLNonNull(valueWithTrend),
      resolve(_o, _a, ctx) {
        return slowdownValue(ctx.slowdown, {
          value: 249,
          trend: "Neutral",
        });
      },
    },
    newUsers: {
      type: new GraphQLNonNull(valueWithTrend),
      resolve(_o, _a, ctx) {
        return slowdownValue(ctx.slowdown, {
          value: 2,
          trend: "Up",
        });
      },
    },
    serverUptime: {
      type: new GraphQLNonNull(valueWithTrend),
      resolve(_o, _a, ctx) {
        return slowdownValue(ctx.slowdown, {
          value: 152,
          trend: "Up",
        });
      },
    },
    todoList: {
      type: new GraphQLNonNull(valueWithTrend),
      resolve(_o, _a, ctx) {
        return slowdownValue(ctx.slowdown, {
          value: 7,
          trend: "Down",
        });
      },
    },
    issues: {
      type: new GraphQLNonNull(valueWithTrend),
      resolve(_o, _a, ctx) {
        return slowdownValue(ctx.slowdown, {
          value: 3,
          trend: "Up",
        });
      },
    },
  }),
});

/**
 * Root types
 */

const query = new GraphQLObjectType({
  name: "Query",
  fields: () => ({
    node: nodeField,
    loggedInUser: {
      type: new GraphQLNonNull(user),
      resolve() {
        return loggedInUser;
      },
    },
    statistics: {
      type: new GraphQLNonNull(stats),
      resolve(_root, _args, ctx) {
        return {};
      },
    },
  }),
});

const mutation = new GraphQLObjectType({
  name: "Mutation",
  fields: () => ({
    addTask: {
      args: {
        title: {
          type: new GraphQLNonNull(GraphQLString),
        },
        body: {
          type: GraphQLString,
        },
        priority: {
          type: new GraphQLNonNull(taskPriorityEnum),
        },
      },
      type: new GraphQLObjectType({
        name: "AddTaskPayload",
        fields: () => ({
          addedTaskEdge: {
            type: taskEdge,
          },
        }),
      }),
      resolve(_, args) {
        const newTask = {
          type: "Task",
          id: `task-${taskId++}`,
          createdAt: Date.now(),
          title: args.title,
          body: args.body,
          priority: args.priority,
          assignee: null,
        };

        tasks.push(newTask);

        return {
          addedTaskEdge: {
            node: newTask,
          },
        };
      },
    },
    updateTask: {
      args: {
        id: {
          type: new GraphQLNonNull(GraphQLID),
        },
        title: {
          type: GraphQLString,
        },
        body: {
          type: GraphQLString,
        },
        priority: {
          type: taskPriorityEnum,
        },
        assignee: {
          type: GraphQLID,
        },
      },
      type: new GraphQLObjectType({
        name: "UpdateTaskPayload",
        fields: () => ({
          updatedTask: {
            type: task,
          },
        }),
      }),
      resolve(_, args) {
        const currentTask = tasks.find((t) => t.id === args.id);

        if (!currentTask) {
          throw new Error("Task not found.");
        }

        const { title, body, priority, assignee } = args;

        if (title != null) {
          currentTask.title = title;
        }

        if (typeof body !== "undefined") {
          currentTask.body = body;
        }

        if (priority != null) {
          currentTask.priority = priority;
        }

        if (assignee != null) {
          currentTask.assignee = assignee;
        }

        return {
          updatedTask: currentTask,
        };
      },
    },
    deleteTask: {
      args: {
        id: {
          type: new GraphQLNonNull(GraphQLID),
        },
      },
      type: new GraphQLObjectType({
        name: "DeleteTaskPayload",
        fields: () => ({
          deletedTaskId: {
            type: GraphQLID,
          },
        }),
      }),
      resolve(_, args) {
        const currentTaskIndex = tasks.findIndex((t) => t.id === args.id);

        if (currentTaskIndex === -1) {
          throw new Error("Task not found.");
        }

        tasks.splice(currentTaskIndex, 1);

        return {
          deletedTaskId: toGlobalId("Task", tasks[currentTaskIndex].id),
        };
      },
    },
  }),
});

const schema = new GraphQLSchema({
  query,
  mutation,
  experimentalDefer: true,
});

module.exports = {
  schema,
};
