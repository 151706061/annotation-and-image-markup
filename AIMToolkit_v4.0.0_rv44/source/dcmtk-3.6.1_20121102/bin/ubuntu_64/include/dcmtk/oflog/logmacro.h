/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

/** @file
 * This header defines the logging macros. */

#ifndef DCMTK__LOG4CPLUS_LOGGING_MACROS_HEADER_
#define DCMTK__LOG4CPLUS_LOGGING_MACROS_HEADER_

#include "dcmtk/oflog/config.h"
#include "dcmtk/oflog/streams.h"


#if defined(LOG4CPLUS_DISABLE_FATAL) && !defined(LOG4CPLUS_DISABLE_ERROR)
#define LOG4CPLUS_DISABLE_ERROR
#endif
#if defined(LOG4CPLUS_DISABLE_ERROR) && !defined(LOG4CPLUS_DISABLE_WARN)
#define LOG4CPLUS_DISABLE_WARN
#endif
#if defined(LOG4CPLUS_DISABLE_WARN) && !defined(LOG4CPLUS_DISABLE_INFO)
#define LOG4CPLUS_DISABLE_INFO
#endif
#if defined(LOG4CPLUS_DISABLE_INFO) && !defined(LOG4CPLUS_DISABLE_DEBUG)
#define LOG4CPLUS_DISABLE_DEBUG
#endif
#if defined(LOG4CPLUS_DISABLE_DEBUG) && !defined(LOG4CPLUS_DISABLE_TRACE)
#define LOG4CPLUS_DISABLE_TRACE
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1400
#  define DCMTK_LOG4CPLUS_MACRO_FUNCTION() __FUNCSIG__
#elif defined(__GNUC__)
#  if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    define DCMTK_LOG4CPLUS_MACRO_FUNCTION() __PRETTY_FUNCTION__
#  else
#    define DCMTK_LOG4CPLUS_MACRO_FUNCTION() __FUNCTION__
#  endif
#else
#  define DCMTK_LOG4CPLUS_MACRO_FUNCTION() ""
#endif

#if defined (DCMTK_LOG4CPLUS_SINGLE_THREADED)

namespace dcmtk
{
namespace log4cplus
{

extern DCMTK_LOG4CPLUS_EXPORT tostringstream _macros_oss;

DCMTK_LOG4CPLUS_EXPORT void _clear_tostringstream (tostringstream &);

} // namespace log4cplus
} // namespace dcmtk

#define DCMTK_LOG4CPLUS_MACRO_BODY(logger, logEvent, logLevel)                \
    do {                                                                \
        if((logger).isEnabledFor(dcmtk::log4cplus::logLevel##_LOG_LEVEL)) {    \
            dcmtk::log4cplus::_clear_tostringstream (dcmtk::log4cplus::_macros_oss);  \
            dcmtk::log4cplus::_macros_oss << logEvent << OFStringStream_ends;  \
            OFSTRINGSTREAM_GETOFSTRING(dcmtk::log4cplus::_macros_oss, _macros_string) \
            (logger).forcedLog(dcmtk::log4cplus::logLevel##_LOG_LEVEL,         \
                _macros_string, __FILE__, __LINE__,                     \
                DCMTK_LOG4CPLUS_MACRO_FUNCTION());                            \
        }                                                               \
    } while (0)


#else // defined (DCMTK_LOG4CPLUS_SINGLE_THREADED)

#define DCMTK_LOG4CPLUS_MACRO_BODY(logger, logEvent, logLevel)                \
    do {                                                                \
        if((logger).isEnabledFor(dcmtk::log4cplus::logLevel##_LOG_LEVEL)) {    \
            dcmtk::log4cplus::tostringstream _log4cplus_buf;                   \
            _log4cplus_buf << logEvent << OFStringStream_ends;          \
            OFSTRINGSTREAM_GETOFSTRING(_log4cplus_buf, _macro_string)   \
            (logger).forcedLog(dcmtk::log4cplus::logLevel##_LOG_LEVEL,         \
                _macro_string, __FILE__, __LINE__,                      \
                DCMTK_LOG4CPLUS_MACRO_FUNCTION());                            \
        }                                                               \
    } while (0)


#endif // defined (DCMTK_LOG4CPLUS_SINGLE_THREADED)

#define DCMTK_LOG4CPLUS_MACRO_STR_BODY(logger, logEvent, logLevel)            \
    do {                                                                \
        if((logger).isEnabledFor(dcmtk::log4cplus::logLevel##_LOG_LEVEL)) {    \
            (logger).forcedLog(dcmtk::log4cplus::logLevel##_LOG_LEVEL,         \
                logEvent, __FILE__, __LINE__,                           \
                DCMTK_LOG4CPLUS_MACRO_FUNCTION());                            \
        }                                                               \
    } while(0)


/**
 * @def DCMTK_LOG4CPLUS_TRACE_METHOD(logger, logEvent)  This macro creates a TraceLogger
 * to log a TRACE_LOG_LEVEL message to <code>logger</code> upon entry and
 * exiting of a method.
 * <code>logEvent</code> will be streamed into an <code>ostream</code>.
 */
#if !defined(LOG4CPLUS_DISABLE_TRACE)
#define DCMTK_LOG4CPLUS_TRACE_METHOD(logger, logEvent)                        \
    dcmtk::log4cplus::TraceLogger _log4cplus_trace_logger(logger, logEvent,    \
                                                   __FILE__, __LINE__);
#define DCMTK_LOG4CPLUS_TRACE(logger, logEvent)                               \
    DCMTK_LOG4CPLUS_MACRO_BODY (logger, logEvent, TRACE)
#define DCMTK_LOG4CPLUS_TRACE_STR(logger, logEvent)                           \
    DCMTK_LOG4CPLUS_MACRO_STR_BODY (logger, logEvent, TRACE)
#else
#define DCMTK_LOG4CPLUS_TRACE_METHOD(logger, logEvent) do { } while (0)
#define DCMTK_LOG4CPLUS_TRACE(logger, logEvent) do { } while (0)
#define DCMTK_LOG4CPLUS_TRACE_STR(logger, logEvent) do { } while (0)
#endif

/**
 * @def DCMTK_LOG4CPLUS_DEBUG(logger, logEvent)  This macro is used to log a
 * DEBUG_LOG_LEVEL message to <code>logger</code>.
 * <code>logEvent</code> will be streamed into an <code>ostream</code>.
 */
#if !defined(LOG4CPLUS_DISABLE_DEBUG)
#define DCMTK_LOG4CPLUS_DEBUG(logger, logEvent)                               \
    DCMTK_LOG4CPLUS_MACRO_BODY (logger, logEvent, DEBUG)
#define DCMTK_LOG4CPLUS_DEBUG_STR(logger, logEvent)                           \
    DCMTK_LOG4CPLUS_MACRO_STR_BODY (logger, logEvent, DEBUG)
#else
#define DCMTK_LOG4CPLUS_DEBUG(logger, logEvent) do { } while (0)
#define DCMTK_LOG4CPLUS_DEBUG_STR(logger, logEvent) do { } while (0)
#endif

/**
 * @def DCMTK_LOG4CPLUS_INFO(logger, logEvent)  This macro is used to log a
 * INFO_LOG_LEVEL message to <code>logger</code>.
 * <code>logEvent</code> will be streamed into an <code>ostream</code>.
 */
#if !defined(LOG4CPLUS_DISABLE_INFO)
#define DCMTK_LOG4CPLUS_INFO(logger, logEvent)                                \
    DCMTK_LOG4CPLUS_MACRO_BODY (logger, logEvent, INFO)
#define DCMTK_LOG4CPLUS_INFO_STR(logger, logEvent)                            \
    DCMTK_LOG4CPLUS_MACRO_STR_BODY (logger, logEvent, INFO)
#else
#define DCMTK_LOG4CPLUS_INFO(logger, logEvent) do { } while (0)
#define DCMTK_LOG4CPLUS_INFO_STR(logger, logEvent) do { } while (0)
#endif

/**
 * @def DCMTK_LOG4CPLUS_WARN(logger, logEvent)  This macro is used to log a
 * WARN_LOG_LEVEL message to <code>logger</code>.
 * <code>logEvent</code> will be streamed into an <code>ostream</code>.
 */
#if !defined(LOG4CPLUS_DISABLE_WARN)
#define DCMTK_LOG4CPLUS_WARN(logger, logEvent)                                \
    DCMTK_LOG4CPLUS_MACRO_BODY (logger, logEvent, WARN)
#define DCMTK_LOG4CPLUS_WARN_STR(logger, logEvent)                            \
    DCMTK_LOG4CPLUS_MACRO_STR_BODY (logger, logEvent, WARN)
#else
#define DCMTK_LOG4CPLUS_WARN(logger, logEvent) do { } while (0)
#define DCMTK_LOG4CPLUS_WARN_STR(logger, logEvent) do { } while (0)
#endif

/**
 * @def DCMTK_LOG4CPLUS_ERROR(logger, logEvent)  This macro is used to log a
 * ERROR_LOG_LEVEL message to <code>logger</code>.
 * <code>logEvent</code> will be streamed into an <code>ostream</code>.
 */
#if !defined(LOG4CPLUS_DISABLE_ERROR)
#define DCMTK_LOG4CPLUS_ERROR(logger, logEvent)                               \
    DCMTK_LOG4CPLUS_MACRO_BODY (logger, logEvent, ERROR)
#define DCMTK_LOG4CPLUS_ERROR_STR(logger, logEvent)                           \
    DCMTK_LOG4CPLUS_MACRO_STR_BODY (logger, logEvent, ERROR)
#else
#define DCMTK_LOG4CPLUS_ERROR(logger, logEvent) do { } while (0)
#define DCMTK_LOG4CPLUS_ERROR_STR(logger, logEvent) do { } while (0)
#endif

/**
 * @def DCMTK_LOG4CPLUS_FATAL(logger, logEvent)  This macro is used to log a
 * FATAL_LOG_LEVEL message to <code>logger</code>.
 * <code>logEvent</code> will be streamed into an <code>ostream</code>.
 */
#if !defined(LOG4CPLUS_DISABLE_FATAL)
#define DCMTK_LOG4CPLUS_FATAL(logger, logEvent)                               \
    DCMTK_LOG4CPLUS_MACRO_BODY (logger, logEvent, FATAL)
#define DCMTK_LOG4CPLUS_FATAL_STR(logger, logEvent)                           \
    DCMTK_LOG4CPLUS_MACRO_STR_BODY (logger, logEvent, FATAL)
#else
#define DCMTK_LOG4CPLUS_FATAL(logger, logEvent) do { } while (0)
#define DCMTK_LOG4CPLUS_FATAL_STR(logger, logEvent) do { } while (0)
#endif

#endif /* DCMTK__LOG4CPLUS_LOGGING_MACROS_HEADER_ */

