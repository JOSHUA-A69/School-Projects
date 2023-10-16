document.body.addEventListener("click", function (e) {
    if (e.target.id === "goToIndex") {
      // Prevent the default link behavior
      e.preventDefault();
      // Add a zoom-in class to the body
      document.body.classList.add("zoom-in");
      // Wait for the transition to complete and then navigate to index.html
      setTimeout(function () {
        window.location.href = "index.html";
      }, 500);
    }
  });
  
  window.addEventListener("popstate", function (e) {
    if (e.state && e.state.page === "index") {
        // Add a class for reverse transition effect
        document.body.classList.add("zoom-out");
  
        // Set a timeout to redirect back to index
        setTimeout(function () {
            window.location.href = "index.html";
        }, 500);
    }
  });