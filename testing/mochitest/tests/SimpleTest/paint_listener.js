(function() {
  var accumulatedRect = null;
  var onpaint = function() {};
  var debug = false;
  const FlushModes = {
    FLUSH: 0,
    NOFLUSH: 1
  };

  function paintListener(event) {
    if (event.target != window)
      return;
    var eventRect =
      [ event.boundingClientRect.left,
        event.boundingClientRect.top,
        event.boundingClientRect.right,
        event.boundingClientRect.bottom ];
    if (debug) {
      dump("got MozAfterPaint: " + eventRect.join(",") + "\n");
    }
    accumulatedRect = accumulatedRect
                    ? [ Math.min(accumulatedRect[0], eventRect[0]),
                        Math.min(accumulatedRect[1], eventRect[1]),
                        Math.max(accumulatedRect[2], eventRect[2]),
                        Math.max(accumulatedRect[3], eventRect[3]) ]
                    : eventRect;
    onpaint();
  }
  window.addEventListener("MozAfterPaint", paintListener, false);

  function waitForPaints(callback, subdoc, flushMode) {
    // The call to getBoundingClientRect will flush pending layout
    // notifications. Sometimes, however, this is undesirable since it can mask
    // bugs where the code under test should be performing the flush.
    if (flushMode === FlushModes.FLUSH) {
      document.documentElement.getBoundingClientRect();
      if (subdoc) {
        subdoc.documentElement.getBoundingClientRect();
      }
    }
    var utils = SpecialPowers.getDOMWindowUtils(window);
    if (!utils.isMozAfterPaintPending) {
      if (debug) {
        dump("done...\n");
      }
      var result = accumulatedRect || [ 0, 0, 0, 0 ];
      accumulatedRect = null;
      onpaint = function() {};
      callback.apply(null, result);
      return;
    }
    if (debug) {
      dump("waiting for paint...\n");
    }
    onpaint = function() { waitForPaints(callback, subdoc, flushMode); };
  }

  window.waitForAllPaintsFlushed = function(callback, subdoc) {
    waitForPaints(callback, subdoc, FlushModes.FLUSH);
  };

  window.waitForAllPaints = function(callback) {
    waitForPaints(callback, null, FlushModes.NOFLUSH);
  };
})();
