# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

MaxDouble <- function() {
    .Call('mcgaqt_MaxDouble', PACKAGE = 'mcgaqt')
}

SizeOfDouble <- function() {
    .Call('mcgaqt_SizeOfDouble', PACKAGE = 'mcgaqt')
}

SizeOfInt <- function() {
    .Call('mcgaqt_SizeOfInt', PACKAGE = 'mcgaqt')
}

SizeOfLong <- function() {
    .Call('mcgaqt_SizeOfLong', PACKAGE = 'mcgaqt')
}

DoubleToBytes <- function(x) {
    .Call('mcgaqt_DoubleToBytes', PACKAGE = 'mcgaqt', x)
}

DoubleVectorToBytes <- function(d) {
    .Call('mcgaqt_DoubleVectorToBytes', PACKAGE = 'mcgaqt', d)
}

BytesToDouble <- function(x) {
    .Call('mcgaqt_BytesToDouble', PACKAGE = 'mcgaqt', x)
}

ByteVectorToDoubles <- function(b) {
    .Call('mcgaqt_ByteVectorToDoubles', PACKAGE = 'mcgaqt', b)
}

OnePointCrossOver <- function(bytes1, bytes2, cutpoint) {
    .Call('mcgaqt_OnePointCrossOver', PACKAGE = 'mcgaqt', bytes1, bytes2, cutpoint)
}

OnePointCrossOverOnDoublesUsingBytes <- function(d1, d2, cutpoint) {
    .Call('mcgaqt_OnePointCrossOverOnDoublesUsingBytes', PACKAGE = 'mcgaqt', d1, d2, cutpoint)
}

TwoPointCrossOver <- function(bytes1, bytes2, cutpoint1, cutpoint2) {
    .Call('mcgaqt_TwoPointCrossOver', PACKAGE = 'mcgaqt', bytes1, bytes2, cutpoint1, cutpoint2)
}

TwoPointCrossOverOnDoublesUsingBytes <- function(d1, d2, cutpoint1, cutpoint2) {
    .Call('mcgaqt_TwoPointCrossOverOnDoublesUsingBytes', PACKAGE = 'mcgaqt', d1, d2, cutpoint1, cutpoint2)
}

UniformCrossOver <- function(bytes1, bytes2) {
    .Call('mcgaqt_UniformCrossOver', PACKAGE = 'mcgaqt', bytes1, bytes2)
}

UniformCrossOverOnDoublesUsingBytes <- function(d1, d2) {
    .Call('mcgaqt_UniformCrossOverOnDoublesUsingBytes', PACKAGE = 'mcgaqt', d1, d2)
}

ByteCodeMutation <- function(bytes1, pmutation) {
    .Call('mcgaqt_ByteCodeMutation', PACKAGE = 'mcgaqt', bytes1, pmutation)
}

ByteCodeMutationUsingDoubles <- function(d, pmutation) {
    .Call('mcgaqt_ByteCodeMutationUsingDoubles', PACKAGE = 'mcgaqt', d, pmutation)
}

ByteCodeMutationUsingDoublesRandom <- function(d, pmutation) {
    .Call('mcgaqt_ByteCodeMutationUsingDoublesRandom', PACKAGE = 'mcgaqt', d, pmutation)
}

EnsureBounds <- function(doubles, mins, maxs) {
    invisible(.Call('mcgaqt_EnsureBounds', PACKAGE = 'mcgaqt', doubles, mins, maxs))
}

