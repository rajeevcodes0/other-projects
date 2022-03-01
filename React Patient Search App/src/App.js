import LogInForm from "./components/utils/LogInForm";

import { useContext } from "react";

import AppManager from "./store/app-manager";
import PanelToggler from "./components/utils/PanelToggler";
import AddUserPanel from "./components/utils/AddUserPanel";
import Header from "./components/utils/Header";
import SearchUserPanel from "./components/utils/SearchUserPanel";

import classes from "./App.module.css";

function App() {
  const appManagerContext = useContext(AppManager);
  // console.log("after adding");
  // console.log(appManagerContext.allPatients);
  return (
    <div className={classes['app-flex-container']}>
      <div className={classes['app-container']}>
        <Header />
        {!appManagerContext.isUserLoggedIn && <LogInForm></LogInForm>}
        {appManagerContext.isUserLoggedIn && <PanelToggler></PanelToggler>}

        {appManagerContext.isUserLoggedIn &&
        appManagerContext.selectedPanel === "add" ? (
          <AddUserPanel />
        ) : (
          ""
        )}

        {appManagerContext.isUserLoggedIn &&
        appManagerContext.selectedPanel === "search" ? (
          <SearchUserPanel />
        ) : (
          ""
        )}
      </div>
    </div>
  );
}

export default App;
