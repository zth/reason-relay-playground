const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const webpack = require("webpack");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");

const outputDir = path.join(__dirname, "assets");
const isDevelopment = process.env.NODE_ENV !== "production";
const isProd = !isDevelopment;

module.exports = {
  entry: "./src/Index.bs.js",
  mode: isDevelopment ? "development" : "production",
  output: {
    path: outputDir,
    publicPath: "/",
    filename: "index.js",
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: "index.html",
    }),
    new webpack.DefinePlugin({
      __DEV__: JSON.stringify(isDevelopment),
    }),
    new MiniCssExtractPlugin({
      filename: !isProd ? "[name].css" : "[name].[hash].css",
      chunkFilename: !isProd ? "[name].[id].css" : "[name].[id].[hash].css",
    }),
  ].filter(Boolean),
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 9000,
    historyApiFallback: true,
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          {
            loader: MiniCssExtractPlugin.loader,
            options: {
              hmr: !isProd,
            },
          },
          { loader: "css-loader" },
          {
            loader: "postcss-loader",
          },
        ],
      },
    ],
  },
};
