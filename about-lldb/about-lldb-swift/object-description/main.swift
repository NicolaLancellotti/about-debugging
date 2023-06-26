struct Temperature {
  var celsiusDegrees: Float
}

extension Temperature: CustomStringConvertible {
  var description: String {
    "Temperature: \(celsiusDegrees) celsius degrees"
  }
}

extension Temperature: CustomDebugStringConvertible {
  var debugDescription: String {
    "Temperature Debug Description"
  }
}

extension Temperature: CustomReflectable {
  var customMirror: Mirror {
    Mirror(self, children: [
      "C" : celsiusDegrees,
      "F" : 1.8 * celsiusDegrees + 32
    ])
  }
}

let temperature = Temperature(celsiusDegrees: 40)
/*
 (lldb) po String(describing: temperature)
 (lldb) p temperature
 (lldb) po temperature
 */
print(temperature)
