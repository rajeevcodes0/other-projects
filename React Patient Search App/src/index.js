import React from "react";
import ReactDOM from "react-dom";
import "./index.css";
import App from "./App";

import { AppManagerProvider } from "./store/app-manager";

ReactDOM.render(
  <AppManagerProvider>
    <App />
  </AppManagerProvider>,
  document.getElementById("root")
);
