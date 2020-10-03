const valueInRange = (min, max) =>
  Math.floor(Math.random() * (max - min + 1) + min);

const slowdownValue = (slowdown, value, offset = 0) =>
  new Promise((resolve) => {
    switch (slowdown) {
      default:
      case "None":
        resolve(value);
        break;
      case "Some": {
        setTimeout(() => {
          resolve(value);
        }, valueInRange(200, 1500 + offset));
        break;
      }
      case "Lots": {
        setTimeout(() => {
          resolve(value);
        }, valueInRange(1000, 4000 + offset));
        break;
      }
    }
  });

module.exports = {
  slowdownValue,
};
