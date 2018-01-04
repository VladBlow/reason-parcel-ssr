[@bs.module "./utils/registerServiceWorker"] external registerServiceWorker : unit => unit =
  "default";

let history = History.createBrowserHistory();

AppShell.bootstrap(history) |> AppShell.onLocationChange(history##location);

registerServiceWorker();